//
// Created by Virusbear on 26.01.2022.
//

#include "OpenGLWindow.h"

namespace CubiLight {
    OpenGLWindow::OpenGLWindow(WindowOpts& opts) {
        m_logger = new Log("OpenGLWindow");

        if(!glfwInit()) {
            m_logger->Fatal("Failed to initialize glfw");
        }

        m_window = glfwCreateWindow(opts.Width, opts.Height, opts.Title.c_str(), nullptr, nullptr);
        if(!m_window) {
            m_logger->Fatal("Failed to create window");
        }

        glfwMakeContextCurrent(m_window);
        if(opts.VsyncEnabled) {
            glfwSwapInterval(1);
        }

        if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            m_logger->Fatal("Failed to load glad");
        }
    }

    OpenGLWindow::~OpenGLWindow() {
        glfwTerminate();
    }

    void *OpenGLWindow::GetNativeWindow() {
        return (void *)m_window;
    }

    void OpenGLWindow::Update() {
        glfwPollEvents();
        glfwSwapBuffers(m_window);

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    bool OpenGLWindow::IsOpen() {
        return !glfwWindowShouldClose(m_window);
    }
}