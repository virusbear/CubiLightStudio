//
// Created by Virusbear on 30.01.2022.
//

#include "Panels/NodeEditor/NodeEditorPanel.h"
#include "Simulation.h"
#include "NodeEditor/NodeRegistry.h"
#include "Panels/NodeEditor/IdStorage.h"
#include "NodeEditor/RendererRegistry.h"

namespace CubiLight {
    NodeEditorPanel::NodeEditorPanel(const std::string name): Panel(name), m_context(ImNodes::CreateContext()), m_nodespace(Simulation::Get().GetNodeSpace()) { }

    NodeEditorPanel::~NodeEditorPanel() {
        ImNodes::DestroyContext(m_context);
    }

    void NodeEditorPanel::Render() {
        auto contextBackup = ImNodes::GetCurrentContext();
        ImNodes::SetCurrentContext(m_context);

        ImNodes::BeginNodeEditor();

        for(auto node : m_nodespace.GetNodes()) {
            RenderNode(node);
        }

        for(auto link : m_nodespace.GetLinks()) {
            RenderLink(link);
        }

        RenderNewNodeMenu();

        ImNodes::MiniMap(0.2f, ImNodesMiniMapLocation_TopRight);
        ImNodes::EndNodeEditor();

        ImNodes::SetCurrentContext(contextBackup);
    }

    void NodeEditorPanel::RenderNewNodeMenu() {
        bool show = ImGui::IsWindowFocused(ImGuiFocusedFlags_RootAndChildWindows) &
                    ImNodes::IsEditorHovered() &&
                    (ImGui::IsMouseReleased(ImGuiMouseButton_Right) || ImGui::IsKeyReleased(ImGuiKey_A)) &&
                    !ImGui::IsAnyItemHovered();

        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(8.f, 8.f));

        if(show) {
            ImGui::OpenPopup("Add Node");
        }

        if(ImGui::BeginPopup("Add Node")) {
            auto mousePos = ImGui::GetMousePosOnOpeningCurrentPopup();

            for(auto type : NodeRegistry::GetRegisteredTypes()) {
                auto toCreate = RenderNewNodeMenuHierarchy(type->Inverse());
                auto node = m_nodespace.AddNode(toCreate);

                if(node != nullptr) {
                    int nodeId = IdStorage::NewNodeId();
                    m_nodes[node] = nodeId;
                    //ImNodes::SetNodeScreenSpacePos(nodeId, mousePos);
                }
            }

            ImGui::EndPopup();
        }

        ImGui::PopStyleVar();
    }

    Type *NodeEditorPanel::RenderNewNodeMenuHierarchy(std::stack<Type *> hierarchy) {
        Type *type = hierarchy.top();
        if(type == nullptr) {
            return nullptr;
        }

        hierarchy.pop();

        if(hierarchy.empty()) {
            if(ImGui::MenuItem(type->type.c_str())) {
                return type;
            }
        } else if(ImGui::BeginMenu(type->type.c_str())) {
            auto toCreate = RenderNewNodeMenuHierarchy(hierarchy);
            ImGui::EndMenu();

            return toCreate;
        }

        return nullptr;
    }

    void NodeEditorPanel::RenderNode(Node *node) {
        int nodeId = GetNodeId(node);

        ImNodes::BeginNode(nodeId);

        ImNodes::BeginNodeTitleBar();
        ImGui::TextUnformatted(node->GetName().c_str());
        ImNodes::EndNodeTitleBar();

        for(auto port : node->GetPorts()) {
            if(port->GetDirection() == PortDirection::Input) {
                RenderInputPort(port);
            } else {
                RenderOutputPort(port);
            }
        }

        ImNodes::EndNode();
    }

    void NodeEditorPanel::RenderInputPort(Port *port) {
        int portId = GetPortId(port);
        ImNodes::PushColorStyle(ImNodesCol_Pin, RendererRegistry::Get(port->GetType())->GetPortColor(port).ToInt(ColorFormat_ABGR));

        ImNodes::BeginInputAttribute(portId, RendererRegistry::Get(port->GetType())->GetPortShape(port));

        RenderPort(port);

        if(!m_nodespace.IsConnected(port)) {
            RendererRegistry::Get(port->GetType())->Render(port);
        }

        ImNodes::EndInputAttribute();

        ImNodes::PopColorStyle();
    }

    void NodeEditorPanel::RenderOutputPort(Port *port) {
        int portId = GetPortId(port);
        ImNodes::PushColorStyle(ImNodesCol_Pin, RendererRegistry::Get(port->GetType())->GetPortColor(port).ToInt(ColorFormat_ABGR));

        ImNodes::BeginOutputAttribute(portId, RendererRegistry::Get(port->GetType())->GetPortShape(port));

        RenderPort(port);

        ImNodes::EndOutputAttribute();

        ImNodes::PopColorStyle();
    }

    void NodeEditorPanel::RenderPort(Port *port) {
        ImGui::TextUnformatted(port->GetName().c_str());
        ImGui::SameLine();
    }

    void NodeEditorPanel::RenderLink(Link *link) {
        ImNodes::Link(
            GetLinkId(link),
            GetPortId((Port *)&(link->start)),
            GetPortId((Port *)&(link->end))
        );
    }

    int NodeEditorPanel::GetPortId(Port *port) {
        if(m_ports.find(port) == m_ports.end()) {
            m_ports[port] = IdStorage::NewPortId();
        }
        return m_ports[port];
    }

    int NodeEditorPanel::GetNodeId(Node *node) {
        if(m_nodes.find(node) == m_nodes.end()) {
            m_nodes[node] = IdStorage::NewNodeId();
        }
        return m_nodes[node];
    }

    int NodeEditorPanel::GetLinkId(Link *link) {
        if(m_links.find(link) == m_links.end()) {
            m_links[link] = IdStorage::NewLinkId();
        }
        return m_links[link];
    }
}