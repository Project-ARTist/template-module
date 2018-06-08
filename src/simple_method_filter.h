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


#ifndef ART_MODULES__STATICMETHODFILTER_H
#define ART_MODULES__STATICMETHODFILTER_H

#include <artist/api/filtering/filter.h>

using std::mutex;

using art::Filter;

class SimpleMethodFilter : public Filter {
public:
  SimpleMethodFilter() : count(0) {};

  bool accept(const art::MethodInfo &info) override;
private:
  // after how many non-static methods we will accept one (restrict number of instrumented methods)
  static int MOD;

  // mutex for atomic `check and write` operation on `count`
  mutex mtx;
  // how many methods did we check already
  int count;
};

#endif //ART_MODULES__STATICMETHODFILTER_H
