//
// Created by Virusbear on 29.01.2022.
//

#include "NodeEditor/PortData/IntPortData.h"

namespace CubiLight {
    void IntPortData::Render() {
        ImGui::SetNextItemWidth(150.0f);
        ImGui::DragInt("##hidden", &value, 0.2f, min, max);
    }

    std::string IntPortData::GetType() {
        return "CubiLight::IntPortData";
    }

    Color IntPortData::GetPortColor() {
        return {53, 150, 250, 180};
    }

    PortShape IntPortData::GetPortShape() {
        return PortShape::CircleFilled;
    }
}