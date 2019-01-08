/*
 * Copyright (C) 2019 The LineageOS Project
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
 */

#include "KeyDisabler.h"

namespace vendor {
namespace lineage {
namespace touch {
namespace V1_0 {
namespace kirin970 {

enum MmiCommandId : int32_t {
    MMI_TYPE_NAV_ENABLE  = 41,
    MMI_TYPE_NAV_DISABLE = 42,
};

KeyDisabler::KeyDisabler() {
    mHwHal = IExtBiometricsFingerprint::getService();
}

// Methods from ::vendor::lineage::touch::V1_0::IKeyDisabler follow.
Return<void> KeyDisabler::setEnabled(bool enabled) {
    if (mHwHal != nullptr) {
        mHwHal->sendCmdToHal(enabled ?
                MmiCommandId::MMI_TYPE_NAV_DISABLE : MmiCommandId::MMI_TYPE_NAV_ENABLE);
    }

    return Void();
}

}  // namespace kirin970
}  // namespace V1_0
}  // namespace touch
}  // namespace lineage
}  // namespace vendor
