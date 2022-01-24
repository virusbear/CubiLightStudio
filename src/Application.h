//
// Created by Virusbear on 23.01.2022.
//
#ifndef CUBILIGHTSTUDIO_APPLICATION_H
#define CUBILIGHTSTUDIO_APPLICATION_H

#include "Log.h"
#include "Window.h"

namespace CubiLight {
    class Application {
    public:
        Application();
        ~Application();
        void Run();
        void Close();
        static Application& Get()  { return *instance; };
    private:
        Log *logger;
        Window *window;
        static Application *instance;
        bool running;
    };
}

#endif //CUBILIGHTSTUDIO_APPLICATION_H
