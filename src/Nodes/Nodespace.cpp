//
// Created by dhorn on 27.06.2022.
//

#include "Nodespace.h"

namespace CubiLight {
    void Nodespace::Evaluate() {
        for(auto node : graph.topologicalSort()) {
            node->Evaluate();
        }
    }

    void Nodespace::operator+=(Node& node) {
        graph += node;
    }

    void Nodespace::operator-=(Node& node) {
        graph -= node;
    }

    Link *Nodespace::link(Port &start, Port &end) {
        if(start.GetDir() != PortDirection::Output || end.GetDir() != PortDirection::Input) {
            return nullptr;
        }

        graph.link(start.GetNode(), end.GetNode());

        return new Link(start, end);
    }

    void Nodespace::operator-=(Link& link) {
        graph.unlink(link.GetStart().GetNode(), link.GetEnd().GetNode());

        delete &link;
    }
}