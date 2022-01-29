//
// Created by Virusbear on 29.01.2022.
//

#include "NodeEditor/PortData/FloatPortData.h"

namespace CubiLight {
    void FloatPortData::Render() {
        ImGui::SetNextItemWidth(150.0f);
        ImGui::DragFloat("##hidden", &value, 0.2f, min, max);
    }

    std::string FloatPortData::GetType() {
        return "CubiLight::FloatPortData";
    }

    Color FloatPortData::GetPortColor() {
        return {53, 150, 250, 180};
    }

    PortShape FloatPortData::GetPortShape() {
        return PortShape::CircleFilled;
    }
}