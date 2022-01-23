//
// Created by Virusbear on 23.01.2022.
//
#ifndef CUBILIGHTSTUDIO_APPLICATION_H
#define CUBILIGHTSTUDIO_APPLICATION_H

#include "Log.h"

namespace CubiLight {
    class Application {
    public:
        Application();
        ~Application();
        void Run();
    private:
        Log *logger;
    };
}

#endif //CUBILIGHTSTUDIO_APPLICATION_H
