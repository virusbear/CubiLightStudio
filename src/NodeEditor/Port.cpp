//
// Created by Virusbear on 29.01.2022.
//

#include "NodeEditor/Port.h"

namespace CubiLight {
    Port::Port(PortDirection dir, Type *type, const std::string name, PortData *data): m_dir(dir), m_type(type), m_name(name), m_data(data) {

    }

    Port::~Port() {
        delete m_data;
    }
}