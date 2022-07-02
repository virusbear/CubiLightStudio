//
// Created by Virusbear on 02.07.2022.
//

#ifndef CUBILIGHTSTUDIO_CONSTANTNODES_H
#define CUBILIGHTSTUDIO_CONSTANTNODES_H

#include "AbstractNode.h"
#include "PrimitivePorts.h"
#include <cmath>

namespace CubiLight {
    class ENode: AbstractNode {
    private:
        FloatPort *mE;
    public:
        ENode(std::string& name): AbstractNode(name), mE(Output<FloatPort> ("E")) {
            mE->SetData(M_E);
        }

        void Evaluate() override {}
    };

    class PiNode: AbstractNode {
    private:
        FloatPort *mPi;
    public:
        PiNode(std::string& name): AbstractNode(name), mPi(Output<FloatPort> ("E")) {
            mPi->SetData(M_PI);
        }

        void Evaluate() override {}
    };
}

#endif //CUBILIGHTSTUDIO_CONSTANTNODES_H
