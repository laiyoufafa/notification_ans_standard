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

#ifndef BASE_NOTIFICATION_ANS_STANDARD_SERVICES_DISTRIBUTED_INCLUDE_DISTRIBUTED_DEVICE_CALLBACK_H
#define BASE_NOTIFICATION_ANS_STANDARD_SERVICES_DISTRIBUTED_INCLUDE_DISTRIBUTED_DEVICE_CALLBACK_H

#include <string>

#include "device_status_change_listener.h"

namespace OHOS {
namespace Notification {
class DistributedDeviceCallback : public DistributedKv::DeviceStatusChangeListener {
public:
    struct IDeviceChange {
        std::function<void(const std::string &deviceId)> OnConnected;
        std::function<void(const std::string &deviceId)> OnDisconnected;
    };
    explicit DistributedDeviceCallback(const IDeviceChange &callback);
    ~DistributedDeviceCallback();

private:
    void OnDeviceChanged(
        const DistributedKv::DeviceInfo &info, const DistributedKv::DeviceChangeType &type) const override;
    DistributedKv::DeviceFilterStrategy GetFilterStrategy() const override;

private:
    IDeviceChange callback_;
};
}  // namespace Notification
}  // namespace OHOS

#endif /* BASE_NOTIFICATION_ANS_STANDARD_SERVICES_DISTRIBUTED_INCLUDE_DISTRIBUTED_DEVICE_CALLBACK_H */