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

#ifndef ART_MODULES_ARTIST_H_
#define ART_MODULES_ARTIST_H_

#include <artist/api/injection/injection_artist.h>

using art::HInjectionArtist;
using art::MethodInfo;
using art::OptimizingCompilerStats;
using art::Injection;

/**
 * Example for an instrumentation pass that makes use of the injection boilerplate code.
 * The idea is to declare to *which* of your codelib methods method calls should be injected *where* in the code.
 */
class HTemplateInjectionArtist : public HInjectionArtist {
public:
    explicit HTemplateInjectionArtist(
            const MethodInfo &method_info,
#ifdef BUILD_MARSHMALLOW
            bool is_in_ssa_form = true,
#endif
            const char *pass_name = "TemplateInjectionArtist", OptimizingCompilerStats *stats = nullptr)
            : HInjectionArtist(method_info
#ifdef BUILD_MARSHMALLOW
            , is_in_ssa_form
#endif
            , pass_name, stats) {
        // Nothing
    }

    vector<shared_ptr<const Injection>> ProvideInjections() const OVERRIDE;
};

#endif  // ART_MODULES_ARTIST_H_
