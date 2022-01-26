//
// Created by Virusbear on 26.01.2022.
//

#include "Window.h"

#include "OpenGLWindow.h"

namespace CubiLight {
    Window *Window::Create(WindowOpts opts) {
#ifdef CL_VULKAN
        //TODO: Create vulkan window
        return nullptr;
#else
        return new OpenGLWindow(opts);
#endif
    }
}