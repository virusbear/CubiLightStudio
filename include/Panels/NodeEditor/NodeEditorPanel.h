//
// Created by Virusbear on 30.01.2022.
//

#ifndef CUBILIGHTSTUDIO_NODEEDITORPANEL_H
#define CUBILIGHTSTUDIO_NODEEDITORPANEL_H

#include "Panel.h"
#include <imnodes.h>
#include "NodeEditor/NodeSpace.h"

namespace CubiLight {
    class NodeEditorPanel: public Panel {
    public:
        explicit NodeEditorPanel(const std::string name);
        ~NodeEditorPanel() override;
        void Render() override;
    private:
        ImNodesContext *m_context;
        NodeSpace& m_nodespace;
    };
}

#endif //CUBILIGHTSTUDIO_NODEEDITORPANEL_H
