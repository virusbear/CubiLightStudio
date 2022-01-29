//
// Created by Virusbear on 27.01.2022.
//

#include "NodeEditor/NodeEditorPanel.h"
#include "NodeEditor/NodeRegistry.h"

namespace CubiLight {
    NodeEditorPanel::NodeEditorPanel(const std::string name): Panel(name) {
        m_context = ImNodes::CreateContext();

        ImNodes::PushAttributeFlag(ImNodesAttributeFlags_EnableLinkDetachWithDragClick);
    }

    NodeEditorPanel::~NodeEditorPanel() {
        for(auto node : m_nodes) {
            delete node;
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
            node->Update();
        }

        ImNodes::MiniMap(0.2f, ImNodesMiniMapLocation_TopRight);
        ImNodes::EndNodeEditor();

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

            for(auto nodeType : NodeRegistry::RegisteredNodes()) {
                if(ImGui::MenuItem(nodeType.c_str())) {
                    auto node = NodeRegistry::Create(nodeType);
                    m_nodes.push_back(node);
                    ImNodes::SetNodeScreenSpacePos(node->GetId(), mousePos);
                }
            }

            ImGui::EndPopup();
        }

        ImGui::PopStyleVar();
    }
}