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
 *
 */

#include <artist/filtering/method_name_filters.h>

#include "module.h"
#include "instrumentation_pass.h"
#include "codelib.h"

using std::make_shared;
using std::unique_ptr;

shared_ptr<HArtist> ArtistModule::createPass(const MethodInfo &method_info) const {
    return make_shared<HModule>(method_info);
}

shared_ptr<const CodeLib> ArtistModule::createCodeLib() const {
    return make_shared<ModuleCodeLib>();
}

// Possible MethodFilter: skip android support lib ui methods since they bloat up the log
unique_ptr<Filter> ArtistModule::getMethodFilter() const {
    const vector<const string> ui = {"android.support."};
    return unique_ptr<Filter>(new art::BlacklistFilter(ui));
}

// the class factories
extern "C" shared_ptr<art::Module> create() {
    return make_shared<ArtistModule>();
}
