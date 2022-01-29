//
// Created by Virusbear on 29.01.2022.
//

#include "NodeEditor/PortData/IVec2PortData.h"

namespace CubiLight {
    IVec2PortData::IVec2PortData() {
        value = IVec2::Zero;
    }
    void IVec2PortData::Render() {
        ImGui::DragInt("Y", &(value.x), 0.2f, min, max);
        ImGui::DragInt("X", &(value.y), 0.2f, min, max);
    }
}
