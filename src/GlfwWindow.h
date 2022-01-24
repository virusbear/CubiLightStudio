//
// Created by Virusbear on 24.01.2022.
//

#ifndef CUBILIGHTSTUDIO_GLFWWINDOW_H
#define CUBILIGHTSTUDIO_GLFWWINDOW_H

#include "Window.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace CubiLight {
    class GlfwWindow: public Window {
    public:
        explicit GlfwWindow(const WindowOpts& opts);
        ~GlfwWindow() override;
        void OnUpdate() override;
        void OnClose() override;
    private:
        void SetHazelColors();
    private:
        Log *logger;
        GLFWwindow *window;
    };
}

#endif //CUBILIGHTSTUDIO_GLFWWINDOW_H
