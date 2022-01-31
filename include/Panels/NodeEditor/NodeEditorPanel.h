//
// Created by Virusbear on 30.01.2022.
//

#ifndef CUBILIGHTSTUDIO_NODEEDITORPANEL_H
#define CUBILIGHTSTUDIO_NODEEDITORPANEL_H

#include "Panel.h"
#include <imnodes.h>
#include "NodeEditor/NodeSpace.h"
#include <stack>
#include <functional>
#include <unordered_map>

namespace CubiLight {
    class NodeEditorPanel: public Panel {
    public:
        explicit NodeEditorPanel(const std::string name);
        ~NodeEditorPanel() override;
        void Render() override;
    private:
        void RenderNewNodeMenu();
        Type *RenderNewNodeMenuHierarchy(std::stack<Type *> hierarchy);
        void RenderNode(Node *node);
        void RenderInputPort(Port *port);
        void RenderOutputPort(Port *port);
        void RenderPort(Port *port);
        void RenderLink(Link *link);
        int GetPortId(Port *port);
        int GetNodeId(Node *node);
        int GetLinkId(Link *link);
    private:
        ImNodesContext *m_context;
        NodeSpace& m_nodespace;
        //TODO: How to remove node id mapping for nodes deleted outside of node editor?
        std::unordered_map<Node *, int> m_nodes;
        //TODO: How to remove port id mapping for ports deleted outside of node editor?
        std::unordered_map<Port *, int> m_ports;
        //TODO: How to remove link id mapping for links deleted outside of node editor?
        std::unordered_map<Link *, int> m_links;
    };
}

#endif //CUBILIGHTSTUDIO_NODEEDITORPANEL_H
