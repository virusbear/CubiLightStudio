//
// Created by Virusbear on 24.01.2022.
//

#ifndef CUBILIGHTSTUDIO_WINDOW_H
#define CUBILIGHTSTUDIO_WINDOW_H

#include "Log.h"

namespace CubiLight {
    struct WindowOpts {
        std::string Title;
        int Width;
        int Height;
        bool VsyncEnabled;

        WindowOpts(
            const std::string& title = "CubiLight Studio",
            int width = 1600,
            int height = 900,
            bool vsyncEnabled = true
        ): Title(title), Width(width), Height(height), VsyncEnabled(vsyncEnabled) { }
    };

    class Window {
    public:
        virtual ~Window() = default;
        virtual void OnUpdate() = 0;
        virtual void OnClose() = 0;

        static Window *Create(const WindowOpts& opts = WindowOpts());
    };
}

#endif //CUBILIGHTSTUDIO_WINDOW_H
