//
// Created by Virusbear on 27.01.2022.
//

#ifndef CUBILIGHTSTUDIO_PORT_H
#define CUBILIGHTSTUDIO_PORT_H

#include <string>
#include <vector>
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
        PortData& GetData() const { return m_data; }
        int GetId() const { return m_id; }
        PortDirection GetDirection() const { return m_dir; }
        bool IsConnected() const { return m_link_id >= -1; }
        int GetLinkId() const { return m_link_id; }
    private:
        int m_id;
        PortData& m_data;
        const std::string m_name;
        PortDirection m_dir;
        int m_link_id;
    };
}
#endif //CUBILIGHTSTUDIO_PORT_H
