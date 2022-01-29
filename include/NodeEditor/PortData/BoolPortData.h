//
// Created by Virusbear on 29.01.2022.
//

#ifndef CUBILIGHTSTUDIO_BOOLPORTDATA_H
#define CUBILIGHTSTUDIO_BOOLPORTDATA_H

#include "NodeEditor/PortData.h"

namespace CubiLight {
    struct BoolPortData: public PortData {
        BoolPortData(): value(false) {}
        bool value;

        void Render() override;
    };
}

#endif //CUBILIGHTSTUDIO_BOOLPORTDATA_H
