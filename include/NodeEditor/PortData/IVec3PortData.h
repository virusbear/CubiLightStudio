//
// Created by Virusbear on 29.01.2022.
//

#ifndef CUBILIGHTSTUDIO_IVEC3PORTDATA_H
#define CUBILIGHTSTUDIO_IVEC3PORTDATA_H

#include <string>
#include "NodeEditor/PortData.h"
#include "Math/IVec2.h"

namespace CubiLight {
    struct IVec3PortData: public PortData {
        IVec3PortData();
        IVec3 value;
        int min;
        int max;

        void Render() override;
        std::string GetType() override;
        Color GetPortColor() override;
        PortShape GetPortShape() override;
    };
}

#endif //CUBILIGHTSTUDIO_IVEC3PORTDATA_H
