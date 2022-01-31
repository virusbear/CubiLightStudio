//
// Created by Virusbear on 31.01.2022.
//

#ifndef CUBILIGHTSTUDIO_BOOLPORTDATA_H
#define CUBILIGHTSTUDIO_BOOLPORTDATA_H

#include "NodeEditor/PortData.h"

namespace CubiLight {
    struct BoolPortData: public PortData {
        bool Value;
        static Type *GetType() { return m_type; }
    private:
        static Type *m_type;
    };
}

#endif //CUBILIGHTSTUDIO_BOOLPORTDATA_H
