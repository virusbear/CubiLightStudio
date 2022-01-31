//
// Created by Virusbear on 30.01.2022.
//

#include "Simulation.h"

namespace CubiLight {
    Simulation *Simulation::m_instance;

    Simulation::Simulation() {
        m_nodespace = new NodeSpace();
    }

    Simulation::~Simulation() {
        delete m_nodespace;
        m_instance = nullptr;
    }

    void Simulation::Init() {
        m_instance = new Simulation();
    }

    Simulation& Simulation::Get() {
        return *m_instance;
    }

    NodeSpace &Simulation::GetNodeSpace() {
        return *m_nodespace;
    }
}