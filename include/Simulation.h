//
// Created by Virusbear on 30.01.2022.
//

#ifndef CUBILIGHTSTUDIO_SIMULATION_H
#define CUBILIGHTSTUDIO_SIMULATION_H

#include "NodeEditor/NodeSpace.h"

namespace CubiLight {
    class Simulation {
    public:
        NodeSpace& GetNodeSpace();
        static void Init();
        static Simulation& Get();
    private:
        Simulation();
        ~Simulation();
        static Simulation *m_instance;
        NodeSpace *m_nodespace;
    };
}

#endif //CUBILIGHTSTUDIO_SIMULATION_H
