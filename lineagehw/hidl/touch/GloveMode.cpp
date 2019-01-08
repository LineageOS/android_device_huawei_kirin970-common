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

#include <fstream>

#include "GloveMode.h"

namespace vendor {
namespace lineage {
namespace touch {
namespace V1_0 {
namespace kirin970 {

// Methods from ::vendor::lineage::touch::V1_0::IGloveMode follow.
Return<void> GloveMode::setEnabled(bool enabled) {
    std::ofstream file("/sys/class/sec/tsp/cmd");
    file << "glove_mode," << (enabled ? "1" : "0");
    return Void();
}

}  // namespace kirin970
}  // namespace V1_0
}  // namespace touch
}  // namespace lineage
}  // namespace vendor
