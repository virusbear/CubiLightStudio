//
// Created by Virusbear on 29.01.2022.
//

#include "NodeEditor/PortData/BoolPortData.h"

namespace CubiLight {
    void BoolPortData::Render() {
        ImGui::Checkbox("##hidden", &value);
    }
}