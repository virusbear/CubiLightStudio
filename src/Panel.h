//
// Created by Virusbear on 24.01.2022.
//

#ifndef CUBILIGHTSTUDIO_PANEL_H
#define CUBILIGHTSTUDIO_PANEL_H

namespace CubiLight {
    class Panel {
    public:
        Panel() = default;
        virtual ~Panel();
        virtual void Render();
    };
}

#endif //CUBILIGHTSTUDIO_PANEL_H
