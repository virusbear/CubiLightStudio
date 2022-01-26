//
// Created by Virusbear on 26.01.2022.
//

#include "Panel.h"

namespace CubiLight {
    bool Panel::Begin(std::string& name) {
        return ImGui::Begin(name.c_str(), &m_show);
    }

    void Panel::End() {
        return ImGui::End();
    }
}