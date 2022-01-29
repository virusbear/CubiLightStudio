//
// Created by Virusbear on 27.01.2022.
//

#include "NodeEditor/NodeEditorPanel.h"
#include "NodeEditor/NodeRegistry.h"
#include <stack>

namespace CubiLight {
    NodeEditorPanel::NodeEditorPanel(const std::string name): Panel(name) {
        m_context = ImNodes::CreateContext();

        //ImNodes::PushAttributeFlag(ImNodesAttributeFlags_EnableLinkDetachWithDragClick);
    }

    NodeEditorPanel::~NodeEditorPanel() {
        for(auto node : m_nodes) {
            delete node.second;
        }
        for(auto link : m_links) {
            delete link.second;
        }
        IdStorage::FreeContext(m_context);

        ImNodes::DestroyContext(m_context);
    }

    void NodeEditorPanel::Render() {
        auto contextBackup = ImNodes::GetCurrentContext();
        ImNodes::SetCurrentContext(m_context);

        ImNodes::BeginNodeEditor();

        RenderNewNodePopup();

        for(auto node : m_nodes) {
            node.second->Update();
        }

        for(auto link : m_links) {
            ImNodes::Link(link.first, link.second->GetStart()->GetId(), link.second->GetEnd()->GetId());
        }

        ImNodes::MiniMap(0.2f, ImNodesMiniMapLocation_TopRight);
        ImNodes::EndNodeEditor();

        DeleteLinks();
        CreateNewLinks();

        ImNodes::SetCurrentContext(contextBackup);
    }

    void NodeEditorPanel::RenderNewNodePopup() {
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

            for(const std::string& nodeType : NodeRegistry::RegisteredNodes()) {
                if(ImGui::MenuItem(nodeType.c_str())) {
                    auto node = NodeRegistry::Create(nodeType);
                    m_nodes[node->GetId()] = node;

                    ImNodes::SetNodeScreenSpacePos(node->GetId(), mousePos);
                }
            }

            ImGui::EndPopup();
        }

        ImGui::PopStyleVar();
    }

    void NodeEditorPanel::CreateNewLinks() {
        int startNodeId, startAttr, endNodeId, endAttr;
        if(ImNodes::IsLinkCreated(&startNodeId, &startAttr, &endNodeId, &endAttr)) {
            assert(m_nodes.find(startNodeId) != m_nodes.end());
            assert(m_nodes.find(endNodeId) != m_nodes.end());

            auto startNode = m_nodes[startNodeId];
            auto endNode = m_nodes[endNodeId];

            auto startPort = startNode->GetPort(startAttr);
            auto endPort = endNode->GetPort(endAttr);

            if(startPort->GetData().GetType() != endPort->GetData().GetType()) {
                return;
            }

            Link *link;
            if(startPort->GetDirection() == PortDirection::Input) {
                link = new Link(IdStorage::NewLinkId(), endPort, startPort);
            } else {
                link = new Link(IdStorage::NewLinkId(), startPort, endPort);
            }

            if(!startNode->CanLink(link) || !endNode->CanLink(link)) {
                return;
            }

            startNode->AddLink(link);
            endNode->AddLink(link);
            m_links[link->GetId()] = link;
        }
    }

    void NodeEditorPanel::Evaluate() {
        std::vector<Node *> nodeStack;

        for(auto node : m_nodes) {
            if(std::find(nodeStack.begin(), nodeStack.end(), node.second) != nodeStack.end()) {
                return;
            }

            nodeStack.push_back(node.second);

            for(auto input : node.second->GetInputs()) {
                if(input->IsConnected()) {
                    int linkId = input->GetLinkId();

                    if(m_links.find(linkId) != m_links.end()) {
                        m_links[linkId].first
                    }
                }
            }
        }
    }
}