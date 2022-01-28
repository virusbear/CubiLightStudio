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
        explicit Panel(const std::string name);
        virtual ~Panel() = default;
        void Update();

    protected:
        virtual void Render() = 0;

    private:
        bool Begin(const std::string& name);
        void End();
        bool m_show = true;
        const std::string m_name;
    };
}

#endif //CUBILIGHTSTUDIO_PANEL_H
