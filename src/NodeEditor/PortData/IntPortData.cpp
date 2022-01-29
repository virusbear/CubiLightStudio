//
// Created by Virusbear on 29.01.2022.
//

#include "NodeEditor/PortData/IntPortData.h"

namespace CubiLight {
    void IntPortData::Render() {
        ImGui::SetNextItemWidth(150.0f);
        ImGui::DragInt("##hidden", &value, 0.2f, min, max);
    }
}