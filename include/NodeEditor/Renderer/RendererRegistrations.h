//
// Created by Virusbear on 31.01.2022.
//

#ifndef CUBILIGHTSTUDIO_RENDERERREGISTRATIONS_H
#define CUBILIGHTSTUDIO_RENDERERREGISTRATIONS_H

#include "NodeEditor/Type.h"
#include "NodeEditor/RendererRegistry.h"
#include "NodeEditor/Renderer/BoolPortRenderer.h"

namespace CubiLight {
    void RegisterRenderers() {
        RendererRegistry::Register(BoolPortData::GetType(), new BoolPortRenderer());
    }
}

#endif //CUBILIGHTSTUDIO_RENDERERREGISTRATIONS_H
