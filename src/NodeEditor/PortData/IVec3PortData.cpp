//
// Created by Virusbear on 29.01.2022.
//

#include "NodeEditor/PortData/IVec3PortData.h"

namespace CubiLight {
    IVec3PortData::IVec3PortData() {
        value = IVec3::Zero;
    }

    void IVec3PortData::Render() {
        ImGui::DragInt("X", &(value.x), 0.2f, min, max);
        ImGui::DragInt("Y", &(value.y), 0.2f, min, max);
        ImGui::DragInt("Z", &(value.z), 0.2f, min, max);
    }

    std::string IVec3PortData::GetType() {
        return "CubiLight::IVec3PortData";
    }

    Color IVec3PortData::GetPortColor() {
        return {53, 150, 250, 180};
    }

    PortShape IVec3PortData::GetPortShape() {
        return PortShape::CircleFilled;
    }
}