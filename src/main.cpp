//
// Created by Virusbear on 23.01.2022.
//

#include "Application.h"
#include "NodeEditor/Nodes/Registrations.h"

int main(int argc, char** argv) {
    CubiLight::RegisterNodes();

    auto app = new CubiLight::Application();
    app->Run();
    delete app;

    return 0;
}
