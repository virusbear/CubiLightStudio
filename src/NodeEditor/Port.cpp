//
// Created by Virusbear on 28.01.2022.
//

#include "NodeEditor/Port.h"
#include "imnodes.h"

namespace CubiLight {
    Port::Port(int id, PortDirection dir, PortData *data, const std::string name):
        m_id(id), m_dir(dir), m_data(*data), m_name(name), m_link_id(-1) {}

    Port::~Port() {
        delete &m_data;
    }

    void Port::Update() {
        ImNodes::PushColorStyle(ImNodesCol_Pin, GetData().GetPortColor().ToInt(ColorFormat_ABGR));

        if(m_dir == PortDirection::Input) {
            //TODO: PinShape based on datatype
            ImNodes::BeginInputAttribute(m_id, GetData().GetPortShape());
        } else {
            ImNodes::BeginOutputAttribute(m_id, GetData().GetPortShape());
        }

        if(m_dir == PortDirection::Input) {
            ImGui::TextUnformatted(m_name.c_str());
            ImGui::SameLine();
            if(!IsConnected()) {
                m_data.Render();
            }
        } else {
            ImGui::SameLine();
            ImGui::TextUnformatted(m_name.c_str());
        }

        if(m_dir == PortDirection::Input) {
            ImNodes::EndInputAttribute();
        } else {
            ImNodes::EndInputAttribute();
        }

        ImNodes::PopColorStyle();
    }
}