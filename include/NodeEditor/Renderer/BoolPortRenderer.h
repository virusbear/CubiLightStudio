//
// Created by Virusbear on 31.01.2022.
//

#ifndef CUBILIGHTSTUDIO_BOOLPORTRENDERER_H
#define CUBILIGHTSTUDIO_BOOLPORTRENDERER_H

#include "NodeEditor/PortRenderer.h"

namespace CubiLight {
    class BoolPortRenderer: public PortRenderer {
    public:
        BoolPortRenderer() = default;
        void Render(Port *port) override;
        Color GetPortColor(Port *port) override;
        PortShape GetPortShape(Port *port) override;
    };
}

#endif //CUBILIGHTSTUDIO_BOOLPORTRENDERER_H
