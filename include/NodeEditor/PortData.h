//
// Created by Virusbear on 29.01.2022.
//

#ifndef CUBILIGHTSTUDIO_PORTDATA_H
#define CUBILIGHTSTUDIO_PORTDATA_H

#include <string>

namespace CubiLight {
    class PortData {
    public:
        virtual ~PortData() = default;
        virtual std::string GetType() = 0;
    };
}

#endif //CUBILIGHTSTUDIO_PORTDATA_H
