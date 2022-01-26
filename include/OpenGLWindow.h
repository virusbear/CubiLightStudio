//
// Created by Virusbear on 26.01.2022.
//

#ifndef CUBILIGHTSTUDIO_OPENGLWINDOW_H
#define CUBILIGHTSTUDIO_OPENGLWINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Window.h"
#include "Log.h"

namespace CubiLight {
    class OpenGLWindow: public Window {
    public:
        explicit OpenGLWindow(WindowOpts& opts);
        ~OpenGLWindow() override;
        void *GetNativeWindow() override;
        void Update() override;
        bool IsOpen() override;
    private:
        GLFWwindow *m_window;
        Log *m_logger;
    };
}
#endif //CUBILIGHTSTUDIO_OPENGLWINDOW_H
