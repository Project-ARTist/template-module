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

#ifndef ART_MODULES_CODELIB_H_
#define ART_MODULES_CODELIB_H_

#include <string>
#include <unordered_set>
#include <artist/api/modules/codelib.h>

using std::string;
using std::unordered_set;

using art::CodeLib;

class TemplateCodeLib : public CodeLib {
public:
  static const string INJECTION_ARTIST_TARGET;
  static const string BASIC_ARTIST_TARGET;


  TemplateCodeLib() = default;

    TemplateCodeLib(const TemplateCodeLib &other) = default;

    TemplateCodeLib(TemplateCodeLib &&other) = default;

    ~TemplateCodeLib() override = default;

    TemplateCodeLib &operator=(const TemplateCodeLib &) = default;

    TemplateCodeLib &operator=(TemplateCodeLib &&) = default;

    unordered_set<string> &getMethods() const override;

    string &getInstanceField() const override;

    string &getCodeClass() const override;
};  // class TemplateCodeLib

#endif  // ART_MODULES_CODELIB_H_
