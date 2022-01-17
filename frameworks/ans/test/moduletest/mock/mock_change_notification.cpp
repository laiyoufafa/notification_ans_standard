/*
 * Copyright (c) 2021 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "change_notification.h"

namespace OHOS {
namespace DistributedKv {
ChangeNotification::ChangeNotification(std::vector<Entry> &&insertEntries, std::vector<Entry> &&updateEntries,
    std::vector<Entry> &&deleteEntries, const std::string &deviceId, const bool isClear)
    : insertEntries_(insertEntries),
      updateEntries_(updateEntries),
      deleteEntries_(deleteEntries),
      deviceId_(deviceId),
      isClear_(isClear)
{}

ChangeNotification::~ChangeNotification()
{}

const std::vector<Entry> &ChangeNotification::GetInsertEntries() const
{
    return this->insertEntries_;
}

const std::vector<Entry> &ChangeNotification::GetUpdateEntries() const
{
    return this->updateEntries_;
}

const std::vector<Entry> &ChangeNotification::GetDeleteEntries() const
{
    return this->deleteEntries_;
}

const std::string &ChangeNotification::GetDeviceId() const
{
    return this->deviceId_;
}

bool ChangeNotification::IsClear() const
{
    return this->isClear_;
}

bool ChangeNotification::Marshalling(Parcel &parcel) const
{
    return true;
}
}  // namespace DistributedKv
}  // namespace OHOS