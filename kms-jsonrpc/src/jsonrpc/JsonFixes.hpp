/*
 * (C) Copyright 2014 Kurento (http://kurento.org/)
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#ifndef JSONFIXES_HPP
#define JSONFIXES_HPP

#include <string>
#include <json/json.h>

namespace kurento
{

namespace JsonFixes
{

// This is a workaround for a bug in jsoncpp that can't get numeric values as string
std::string getString (const Json::Value &value);

} /* JsonFixes */

} /* kurento */

#endif // JSONFIXES_HPP
