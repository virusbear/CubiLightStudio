//
// Created by Virusbear on 26.01.2022.
//

#include "Application.h"
#include "NodeEditor/NodeEditorPanel.h"

#include <thread>

namespace CubiLight {
    Application::Application() {
        m_window = Window::Create(WindowOpts{
            .Title = "CubiLight Studio",
            .Width = 1600,
            .Height = 900,
            .VsyncEnabled = true
        });

        m_uiManager = new UIManager(m_window);
        m_uiManager->AddWindow(new NodeEditorPanel("Node Editor"));
    }

    Application::~Application() {
        delete m_uiManager;
        delete m_window;
    }

    void Application::Run() {
        while(m_window->IsOpen()) {
            m_uiManager->Update();
            m_uiManager->Render();
            m_window->Update();
        }
    }
}