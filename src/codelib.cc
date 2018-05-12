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

#include "codelib.h"

unordered_set<string> &ModuleCodeLib::getMethods() const {
    // TODO: implement methods like example below
    // static string instanceField = "Lsaarland/cispa/artist/codelib/CodeLib;traceLog()V";
    // static unordered_set<string> methods({instanceField});
    static unordered_set<string> methods({});
    return methods;
}

string &ModuleCodeLib::getInstanceField() const {
    // TODO: implement instance fields like example below
    // static string instanceField = "Lsaarland/cispa/artist/codelib/CodeLib;INSTANCE";
    static string instanceField;
    return instanceField;
}

string &ModuleCodeLib::getCodeClass() const {
    // TODO: implement code class like example below
    // static string codeClass = "Lsaarland/cispa/artist/codelib/CodeLib;";
    static string codeClass;
    return codeClass;
}
