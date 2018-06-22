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
 */

#include "codelib.h"


// CODE_GENERATOR //////////////////////////////////////////////////////////////////////////////////////////////////////
// METHODS //////////////////////////////////
const string TemplateCodeLib::_M_SAARLAND_CISPA_ARTIST_CODELIB_CODELIB__BASICARTISTTARGET__IL__V =
    "Lsaarland/cispa/artist/codelib/CodeLib;basicArtistTarget(ILjava/lang/Object;)V";
const string TemplateCodeLib::_M_SAARLAND_CISPA_ARTIST_CODELIB_CODELIB__INJECTIONARTISTTARGET__I__V =
    "Lsaarland/cispa/artist/codelib/CodeLib;injectionArtistTarget(I)V";

// FIELDS ///////////////////////////////////
const string TemplateCodeLib::_F_CODECLASS_INSTANCE =
    "Lsaarland/cispa/artist/codelib/CodeLib;INSTANCE";

// CLASSES //////////////////////////////////
const string TemplateCodeLib::_C_JAVA_LANG_STRING =
    "Ljava/lang/String;";
const string TemplateCodeLib::_C_JAVA_LANG_OBJECT =
    "Ljava/lang/Object;";
const string TemplateCodeLib::_C_CODECLASS =
    "Lsaarland/cispa/artist/codelib/CodeLib;";

unordered_set<string> &TemplateCodeLib::getMethods() const {
    static unordered_set<string> methods({
    TemplateCodeLib::_M_SAARLAND_CISPA_ARTIST_CODELIB_CODELIB__BASICARTISTTARGET__IL__V,
    TemplateCodeLib::_M_SAARLAND_CISPA_ARTIST_CODELIB_CODELIB__INJECTIONARTISTTARGET__I__V,
    });
    return methods;
}

string &TemplateCodeLib::getInstanceField() const {
    static string instanceField = TemplateCodeLib::_F_CODECLASS_INSTANCE;
    return instanceField;
}

string &TemplateCodeLib::getCodeClass() const {
    static string codeClass = TemplateCodeLib::_C_CODECLASS;
    return codeClass;
}


// CODE_GENERATOR END //////////////////////////////////////////////////////////////////////////////////////////////////


