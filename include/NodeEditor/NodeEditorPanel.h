//
// Created by Virusbear on 27.01.2022.
//

#ifndef CUBILIGHTSTUDIO_NODEEDITORPANEL_H
#define CUBILIGHTSTUDIO_NODEEDITORPANEL_H

#include "Panel.h"
#include "imnodes.h"
#include "NodeEditor/Node.h"
#include <vector>
#include <string>

namespace CubiLight {
    class NodeEditorPanel: public Panel {
    public:
        explicit NodeEditorPanel(const std::string name);
        ~NodeEditorPanel() override;
        void Render() override;
    private:
        void SetNodePortStyle();
        void RenderNewNodePopup();
    private:
        ImNodesContext *m_context;
        std::vector<Node *> m_nodes;
    };
}

#endif //CUBILIGHTSTUDIO_NODEEDITORPANEL_H
