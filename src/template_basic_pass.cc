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

#include <atomic>

#include <artist/api/io/artist_log.h>
#include <artist/api/io/error_handler.h>

#include "template_basic_pass.h"
#include "codelib.h"

using std::string;
using std::vector;
using std::find_if;

using art::Instruction;
using art::INFO;
using art::HIntConstant;
using art::HParameterValue;
using art::ErrorHandler;


void HTemplateBasicArtist::RunPass() {
  // This method is invoked for each single method that is compiled by ARTist (and passes your defined filters)

  // You can access information about the current method and its graph (linked basic blocks of IR instructions)
  auto signature = _method_info.GetMethodName(true);
  auto blocks = graph_->GetBlocks();

  // You can use the following for logging
  VLOG(artist) << "Sample log for method " << signature;

  // Now let's inject a call to the codelib method `injectedMethod2`. We will use a utils method to generate an
  // `HInvokeVirtual` IR instruction and embed it into the graph

  // first, find the instruction before which we want to inject our method call. For the sake of simplicity, let's
  // inject as the last instruction of the first block where (almost) only param and constants are located.
  art::HInstruction* cursor = graph_->GetEntryBlock()->GetLastInstruction();

  // we will add a call to this method
  auto codelib_method = TemplateCodeLib::_M_SAARLAND_CISPA_ARTIST_CODELIB_CODELIB__BASICARTISTTARGET__IL__V;

  // we will collect all parameters as HInstructions. Instructions also represent their return value, hence if you
  // want to use the return value of a method invocation, use the invocation instruction as a parameter.
  vector<art::HInstruction*> params;

  // Since codelib methods are virtual methods, the first param always needs to be the codelib.
  // `GetCodeLibInstruction()` lazily injects a codelib instance into the first block of a method or somewhere else
  // if you provide a cursor.
  auto codelib_instruction = GetCodeLibInstruction();
  params.push_back(codelib_instruction);

  // Primitive constants can be added to the graph. Strings can't since they are defined in the dex files.
  HIntConstant* param1 = graph_->GetIntConstant(1337);
  params.push_back(param1);

  // But let's assume the second argument (an object) should be the current method's this pointer. Let's search for it.
  auto param_instructions =_method_info.GetParams();
  auto it = find_if (param_instructions.begin(), param_instructions.end(),
                          [this](HParameterValue* p){return this->_method_info.IsThisParameter(p);});
  auto thiz = *it;
  // if our filter for non-static functions (see `module.cc`) is correct, this should not happen
  if (!thiz) {
    // We can trigger a hard crash at any time (e.g., for debugging reasons). The compilation will stop and a dump
    // including your message will be displayed
    ErrorHandler::abortCompilation("Possible implementation error! Did not find a this pointer in method " + signature);
  }
  params.push_back(thiz);

  // The codelib environment can be obtained from the Artist class
  auto env = getCodeLibEnvironment();

  // The return type is picked from an enum. It is the return type of the codelib method defined in `codelib_method`
  auto return_type = art::Primitive::Type::kPrimVoid;

  // Also declare whether you want to inject the method call *before* `cursor`.
  auto before = false;

  // Finally, create the method call instruction and add it to the method graph
  art::ArtUtils::InjectMethodCall(cursor, codelib_method, params, env, return_type, before);

  // If you dump the method graph now, you can see all instructions added by us (bloats the log, but good for debugging)
  // art::ArtistLog::LogMethod(_method_info);

}
