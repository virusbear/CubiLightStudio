//
// Created by Virusbear on 27.01.2022.
//

#ifndef CUBILIGHTSTUDIO_PORT_H
#define CUBILIGHTSTUDIO_PORT_H

#include <string>
#include "NodeEditor/PortData.h"

namespace CubiLight {
    enum PortDirection {
        Input = 0,
        Output,
        PortDirectionCount
    };

    class Port {
    public:
        Port(int id, PortDirection dir, PortData *data, const std::string name);
        ~Port();
        void Update();
        PortData& GetData() const { return m_data; };
    private:
        int m_id;
        PortData& m_data;
        const std::string m_name;
        PortDirection m_dir;
    };
}
#endif //CUBILIGHTSTUDIO_PORT_H
