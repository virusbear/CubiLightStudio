//
// Created by Virusbear on 27.01.2022.
//

#ifndef CUBILIGHTSTUDIO_NODEEDITORPANEL_H
#define CUBILIGHTSTUDIO_NODEEDITORPANEL_H

#include "Panel.h"
#include "imnodes.h"
#include "NodeEditor/Node.h"
#include <unordered_map>
#include <string>

namespace CubiLight {
    class NodeEditorPanel: public Panel {
    public:
        explicit NodeEditorPanel(const std::string name);
        ~NodeEditorPanel() override;
        void Render() override;
    private:
        void RenderNewNodePopup();
        void CreateNewLinks();
        void Evaluate();
    private:
        ImNodesContext *m_context;
        std::unordered_map<int, Node *> m_nodes;
        std::unordered_map<int, std::pair<Port *, Port *>> m_links;
    };
}

#endif //CUBILIGHTSTUDIO_NODEEDITORPANEL_H
