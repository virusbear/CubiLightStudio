//
// Created by Virusbear on 31.01.2022.
//

#ifndef CUBILIGHTSTUDIO_PORTRENDERER_H
#define CUBILIGHTSTUDIO_PORTRENDERER_H

#include "Port.h"
#include "Math/Color.h"
#include "NodeEditor/PortShape.h"

namespace CubiLight {
    class PortRenderer {
    public:
        virtual void Render(Port *port) = 0;
        virtual Color GetPortColor(Port *port) = 0;
        virtual PortShape GetPortShape(Port *port) = 0;
    };
}

#endif //CUBILIGHTSTUDIO_PORTRENDERER_H
