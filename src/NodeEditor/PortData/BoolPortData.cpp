//
// Created by Virusbear on 29.01.2022.
//

#include "NodeEditor/PortData/BoolPortData.h"

namespace CubiLight {
    void BoolPortData::Render() {
        ImGui::Checkbox("##hidden", &value);
    }

    std::string BoolPortData::GetType() {
        return "CubiLight::BoolPortData";
    }

    Color BoolPortData::GetPortColor() {
        return {53, 150, 250, 180};
    }

    PortShape BoolPortData::GetPortShape() {
        return PortShape::CircleFilled;
    }
}