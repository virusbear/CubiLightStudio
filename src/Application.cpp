//
// Created by Virusbear on 23.01.2022.
//

#include "Application.h"

#include <thread>

namespace CubiLight {
    Application *Application::instance = nullptr;

    Application::Application() {
        logger = new Log("Application");
        WindowOpts opts = WindowOpts{};
        window = Window::Create(opts);

        instance = this;
    }

    Application::~Application() {

    }

    void Application::Close() {
        running = false;
    }

    void Application::Run() {
        logger->Trace("Running Application");

        running = true;

        while(running) {
            window->OnUpdate();
        }

        window->OnClose();
    }
}