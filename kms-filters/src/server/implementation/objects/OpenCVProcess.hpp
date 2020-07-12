/*
 * (C) Copyright 2016 Kurento (http://kurento.org/)
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
#ifndef __OPEN_CV_PROCESS_HPP__
#define __OPEN_CV_PROCESS_HPP__

#include <opencv2/opencv.hpp>
#include <memory>
#include <MediaObject.hpp>

namespace kurento
{
class OpenCVProcess
{
public:
  virtual void process (cv::Mat &mat) = 0;
protected:
  std::shared_ptr<MediaObject> getSharedPtr()
  {
    try {
      return dynamic_cast <MediaObject *> (this)->shared_from_this();
    } catch (...) {
      return std::shared_ptr<MediaObject> ();
    }
  }
};
} /* kurento */

#endif /* __OPEN_CV_PROCESS_HPP__ */
