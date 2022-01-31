//
// Created by Virusbear on 31.01.2022.
//

#include "NodeEditor/Renderer/BoolPortRenderer.h"
#include "NodeEditor/PortData/BoolPortData.h"

namespace CubiLight {
    Color BoolPortRenderer::GetPortColor(Port *port) {
        return {53, 150, 250, 180};
    }

    PortShape BoolPortRenderer::GetPortShape(Port *port) {
        return PortShape::CircleFilled;
    }

    void BoolPortRenderer::Render(Port *port) {
        ImGui::Checkbox("##hidden", &((BoolPortData&)(port->GetData())).Value);
    }
}