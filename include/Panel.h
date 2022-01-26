//
// Created by Virusbear on 26.01.2022.
//

#ifndef CUBILIGHTSTUDIO_PANEL_H
#define CUBILIGHTSTUDIO_PANEL_H

#include <string>

#include <imgui.h>
#ifdef CL_VULKAN
    #include <imgui_impl_glfw.h>
    #include <imgui_impl_vulkan.h>
#else
    #include <imgui_impl_glfw.h>
    #include <imgui_impl_opengl3.h>
#endif

namespace CubiLight {
    class Panel {
    public:
        Panel() = default;
        virtual ~Panel() = default;
        virtual void Update() = 0;
    private:
        virtual bool Begin(std::string& name);
        void End();
        bool m_show = true;
    };
}

#endif //CUBILIGHTSTUDIO_PANEL_H
