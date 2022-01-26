//
// Created by Virusbear on 26.01.2022.
//

#ifndef CUBILIGHTSTUDIO_IMGUIDEMOPANEL_H
#define CUBILIGHTSTUDIO_IMGUIDEMOPANEL_H

#include <imgui.h>
#include "Panel.h"

namespace CubiLight {
    class ImGuiDemoPanel: public Panel {
        void Update() override {
            ImGui::ShowDemoWindow();
        }
    };
}

#endif //CUBILIGHTSTUDIO_IMGUIDEMOPANEL_H
