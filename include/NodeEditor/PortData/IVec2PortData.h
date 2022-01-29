//
// Created by Virusbear on 29.01.2022.
//

#ifndef CUBILIGHTSTUDIO_IVEC2PORTDATA_H
#define CUBILIGHTSTUDIO_IVEC2PORTDATA_H

#include "NodeEditor/PortData.h"
#include "Math/IVec2.h"

namespace CubiLight {
    struct IVec2PortData: public PortData {
        IVec2PortData();
        IVec2 value;
        int min;
        int max;

        void Render() override;
    };
}

#endif //CUBILIGHTSTUDIO_IVEC2PORTDATA_H
