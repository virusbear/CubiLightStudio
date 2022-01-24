//
// Created by Virusbear on 24.01.2022.
//

#include "Window.h"
#include "GlfwWindow.h"

namespace CubiLight {
    Window *Window::Create(const WindowOpts& opts) {
        return new GlfwWindow(opts);
    }
}