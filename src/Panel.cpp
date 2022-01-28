//
// Created by Virusbear on 26.01.2022.
//

#include "Panel.h"

namespace CubiLight {
    Panel::Panel(const std::string name): m_name(name) {}

    void Panel::Update() {
        if(m_show) {
            if(Begin(m_name)) {
                Render();
                End();
            }
        }
    }

    bool Panel::Begin(const std::string& name) {
        return ImGui::Begin(name.c_str(), &m_show);
    }

    void Panel::End() {
        return ImGui::End();
    }
}