//
// Created by Virusbear on 26.01.2022.
//

#ifndef CUBILIGHTSTUDIO_WINDOWMANAGER_H
#define CUBILIGHTSTUDIO_WINDOWMANAGER_H

#include "Window.h"
#include "Panel.h"
#include <vector>

#include <imgui.h>

#ifdef CL_VULKAN
    //TODO: Include Vulkan header
#else
    #include "GLFW/glfw3.h"
    #include <imgui_impl_glfw.h>
    #include <imgui_impl_opengl3.h>
#endif

namespace CubiLight {
    class UIManager {
    public:
        explicit UIManager(Window *window);
        ~UIManager();
        void Update();
        void Render();
        void AddWindow(Panel *window);
    private:
        std::vector<Panel *> m_windows;
        void ShowDockSpace(bool *open);
        void SetStyle();
        void UpdateWindows();
    };
}

#endif //CUBILIGHTSTUDIO_WINDOWMANAGER_H
