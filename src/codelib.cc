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

#include "codelib.h"

const std::string TemplateCodeLib::INJECTION_ARTIST_TARGET("Lsaarland/cispa/artist/codelib/CodeLib;injectionArtistTarget(I)V");
const std::string TemplateCodeLib::BASIC_ARTIST_TARGET("Lsaarland/cispa/artist/codelib/CodeLib;basicArtistTarget(ILjava/lang/Object;)V");


unordered_set<string> &TemplateCodeLib::getMethods() const {
  // here we expose the signatures of codelib methods that are meant to be used from ARTist
  static unordered_set<string> methods({INJECTION_ARTIST_TARGET, BASIC_ARTIST_TARGET});
  return methods;
}

string &TemplateCodeLib::getInstanceField() const {
  // here we expose the static field with our singleton instance. This will be used by ARTist to obtain an instance
  // of the codelib to call methods on it.
  static string instanceField = "Lsaarland/cispa/artist/codelib/CodeLib;INSTANCE";
  return instanceField;
}

string &TemplateCodeLib::getCodeClass() const {
  // here we expose the codelib's java class to be able to load it in ARTist
  static string codeClass = "Lsaarland/cispa/artist/codelib/CodeLib;";
  return codeClass;
}
