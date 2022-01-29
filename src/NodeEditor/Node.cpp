//
// Created by Virusbear on 28.01.2022.
//

#include "NodeEditor/Node.h"

namespace CubiLight {
    Node::Node(const std::string name, int id): m_name(name), m_id(id) {}

    Node::~Node() {
        for(auto port : m_ports) {
            delete port;
        }
    }

    void Node::Update() {
        ImNodes::BeginNode(m_id);

        ImNodes::BeginNodeTitleBar();
        ImGui::TextUnformatted(m_name.c_str());
        ImNodes::EndNodeTitleBar();

        for(auto port : m_ports) {
            port->Update();
        }

        ImNodes::EndNode();
    }
}