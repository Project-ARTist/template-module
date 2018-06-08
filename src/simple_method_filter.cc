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
 * @author "Oliver Schranz <oliver.schranz@cispa.saarland>"
 *
 */

#include "simple_method_filter.h"

int SimpleMethodFilter::MOD = 1000000;

/**
 * Simple filter implementation that rejects all static methods and for all others only accepts after seeing `MOD`
 * methods. The reason is that in our (template) injection we write a lot to logcat and hence should avoid to inject
 * calls to this method too often.
 *
 * @param info information & data about the currently compiled method
 * @return
 */
bool SimpleMethodFilter::accept(const art::MethodInfo &info) {
  if (info.IsStatic()) {
    return false;
  }

  mtx.lock();
  bool res =  count == 0;
  count = (count + 1) % SimpleMethodFilter::MOD;
  mtx.unlock();
  return res;
}

