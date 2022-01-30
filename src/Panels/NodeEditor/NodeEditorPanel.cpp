//
// Created by Virusbear on 30.01.2022.
//

#include "Panels/NodeEditor/NodeEditorPanel.h"
#include "Simulation.h"


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
            //TODO: render nodes;
        }

        for(auto link : m_nodespace.GetLinks()) {
            //TODO: render links;
        }

        ImNodes::MiniMap(0.2f, ImNodesMiniMapLocation_TopRight);
        ImNodes::EndNodeEditor();

        ImNodes::SetCurrentContext(contextBackup);
    }
}