//
// Created by Virusbear on 29.01.2022.
//

#ifndef CUBILIGHTSTUDIO_PORT_H
#define CUBILIGHTSTUDIO_PORT_H

#include <string>
#include "PortData.h"
#include "Type.h"

namespace CubiLight {
    enum PortDirection {
        Input,
        Output
    };

    class Port {
    public:
        Port(PortDirection dir, Type *type, const std::string name, PortData *data);
        ~Port();
        PortDirection GetDirection() const { return m_dir; }
        PortData& GetData() const { return *m_data; }
        Type *GetType() const { return m_type; }
    private:
        PortDirection m_dir;
        const std::string m_name;
        PortData *m_data;
        Type *m_type;
    };
}

#endif //CUBILIGHTSTUDIO_PORT_H
