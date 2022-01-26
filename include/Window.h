//
// Created by Virusbear on 26.01.2022.
//

#ifndef CUBILIGHTSTUDIO_WINDOW_H
#define CUBILIGHTSTUDIO_WINDOW_H

#include <string>

namespace CubiLight {
    struct WindowOpts {
        const std::string Title;
        int Width;
        int Height;
        bool VsyncEnabled;
    };

    class Window {
    public:
        virtual ~Window() = default;
        virtual void *GetNativeWindow() { return nullptr; };
        virtual void Update() = 0;
        virtual bool IsOpen() = 0;
        static Window *Create(WindowOpts opts);
    };
}

#endif //CUBILIGHTSTUDIO_WINDOW_H
