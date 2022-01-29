//
// Created by Virusbear on 29.01.2022.
//

#ifndef CUBILIGHTSTUDIO_LINK_H
#define CUBILIGHTSTUDIO_LINK_H

#include "Port.h"

namespace CubiLight {
    struct Link {
        const Port& start;
        const Port& end;
    };
}

#endif //CUBILIGHTSTUDIO_LINK_H
