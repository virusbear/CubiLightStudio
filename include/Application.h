//
// Created by Virusbear on 26.01.2022.
//

#ifndef CUBILIGHTSTUDIO_APPLICATION_H
#define CUBILIGHTSTUDIO_APPLICATION_H

#include "Window.h"
#include "UIManager.h"

namespace CubiLight {
    class Application {
    public:
        Application();
        ~Application();
        void Run();
    private:
        Window *m_window;
        UIManager *m_uiManager;
    };
}
#endif //CUBILIGHTSTUDIO_APPLICATION_H
