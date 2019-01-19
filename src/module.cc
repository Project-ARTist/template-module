/**
 * The ARTist Project (https://artist.cispa.saarland)
 *
 * Copyright (C) 2018 CISPA (https://cispa.saarland), Saarland University
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * @author "Parthipan Ramesh <parthipan.ramesh@cispa.saarland>"
 * @author "Oliver Schranz <oliver.schranz@cispa.saarland>"
 *
 */

#include <artist/api/filtering/method_name_filters.h>

#include "module.h"
//#include "template_basic_pass.h"
#include "template_injection_pass.h"
#include "codelib.h"
#include "simple_method_filter.h"

using std::make_shared;
using std::unique_ptr;

using art::ModuleId;

TemplateModule::TemplateModule(const shared_ptr<const art::FilesystemHelper> fs) : Module(fs) {}

HArtist * TemplateModule::createPass(const MethodInfo &method_info) const {
    // Due to the *clone bug* (https://github.com/Project-ARTist/ARTist/issues/10), we can only define one pass per
    // module right now, but this will change as soon as this bug is resolved.
  return new  HTemplateInjectionArtist(method_info);
//  return new  HTemplateBasicArtist(method_info);

// no arena allocation for now, see Project-ARTist/meta#23
//  return new (method_info.GetGraph()->GetArena()) HTemplateInjectionArtist(method_info);
//  return new (method_info.GetGraph()->GetArena()) HTemplateBasicArtist(method_info);
}

shared_ptr<const CodeLib> TemplateModule::createCodeLib() const {
    return make_shared<TemplateCodeLib>();
}


// Here we can restrict for which methods our module should be executed.
unique_ptr<Filter> TemplateModule::getMethodFilter() const {
    // creating blacklists/whitelists for method names is straightforward:
    // const vector<const string> ui = {"android.support."};
    // return unique_ptr<Filter>(new MethodNameBlacklist(ui));

    // but here we use a custom filter that only excepts non-static methods (and only a fragment of the others)
    return unique_ptr<Filter>(new SimpleMethodFilter());
}
// the module factory
extern "C" shared_ptr<Module> create(shared_ptr<const FilesystemHelper> fshelper) {
    return make_shared<TemplateModule>(fshelper);
}

extern "C" ModuleId get_id() {
  return "saarland.cispa.artist.module.template";
}
