//
// Created by Virusbear on 23.01.2022.
//

#include "Application.h"

namespace CubiLight {
    Application::Application() {
        logger = new Log("Application");
    }

    Application::~Application() {

    }

    void Application::Run() {
        logger->Trace("Running Application");
        while(true);
    }
}