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
#include <artist/api/env/java_env.h>
#include <artist/api/injection/integer.h>
#include <artist/api/io/verbose_printer.h>

#include "template_injection_pass.h"
#include "codelib.h"

using std::string;
using std::vector;
using std::shared_ptr;
using std::make_shared;
using std::endl;
using std::sort;

using art::Parameter;
using art::Integer;
using art::Target;
using art::InjectionTarget;
using art::Target;

vector<shared_ptr<const Injection>> HTemplateInjectionArtist::ProvideInjections() const {
  // You can provide parameters when injecting calls to your methods
  vector<shared_ptr<const Parameter>> params;
  // However, only constants are supported currently.
  auto param1 = make_shared<const Integer>(42);
  params.push_back(param1);

  // Now we define the "Target" which is the definition of *where* to inject. You can define multiple targets here.
  vector<shared_ptr<const Target>> targets;
  // here we define where exactly in the method graph we want to inject. For example, at the end of a method (before
  // each return) or after particular method calls.
  auto injection_target = InjectionTarget::METHOD_END;
  // The restriction can be a (part of) a (pretty printed) signature or simply `Target::GENERIC_TARGET` if you do not
  // want to restrict further. Depending on the injection target defined above, this related to the method currently
  // compiled by ARTist or, if your injection target focuses on method *calls*, then this restriction applies to the
  // signature of the invoked method.
  string target_restriction = Target::GENERIC_TARGET;
  auto target = make_shared<const Target>(target_restriction, injection_target);
  targets.push_back(target);

  // The injection combines the signature of the method we want to inject a call to, its parameters, and the targets
  // we defined earlier.
  auto injection = make_shared<const Injection>(TemplateCodeLib::_M_SAARLAND_CISPA_ARTIST_CODELIB_CODELIB__INJECTIONARTISTTARGET__I__V, params, targets);

  // In theory, you can have as many injections as you want, but due to the so called *clone bug*
  // (https://github.com/Project-ARTist/ARTist/issues/10), this is currently not possible.
  vector<shared_ptr<const Injection>> results;
  results.push_back(injection);

  return results;
}
