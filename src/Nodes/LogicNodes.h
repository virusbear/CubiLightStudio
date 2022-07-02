//
// Created by Virusbear on 02.07.2022.
//

#ifndef CUBILIGHTSTUDIO_LOGICNODES_H
#define CUBILIGHTSTUDIO_LOGICNODES_H

#include "AbstractNode.h"
#include "PrimitivePorts.h"

namespace CubiLight {
    class SwitchNode: AbstractNode {
    private:
        BoolPort *mSwitch;
        VoidPort *mA;
        VoidPort *mB;
        VoidPort *mOutput;
    public:
        SwitchNode(std::string& name): AbstractNode(name), mSwitch(Input<BoolPort>("Switch")), mA(Input<VoidPort>("A")), mB(Input<VoidPort>("B")), mOutput(Output<VoidPort>("Output")) {}

        void Evaluate() override {
            mOutput->SetData(mSwitch->GetData() ? mA->GetData() : mB->GetData());
        }
    };

    class AndNode: AbstractNode {
    private:
        BoolPort *mA;
        BoolPort *mB;
        BoolPort *mOutput;
    public:
        AndNode(std::string& name): AbstractNode(name), mA(Input<BoolPort>("A")), mB(Input<BoolPort>("B")), mOutput(Output<BoolPort>("Output")) {}

        void Evaluate() override {
            mOutput->SetData(mA->GetData() && mB->GetData());
        }
    };

    class OrNode: AbstractNode {
    private:
        BoolPort *mA;
        BoolPort *mB;
        BoolPort *mOutput;
    public:
        OrNode(std::string& name): AbstractNode(name), mA(Input<BoolPort>("A")), mB(Input<BoolPort>("B")), mOutput(Output<BoolPort>("Output")) {}

        void Evaluate() override {
            mOutput->SetData(mA->GetData() || mB->GetData());
        }
    };

    class XorNode: AbstractNode {
    private:
        BoolPort *mA;
        BoolPort *mB;
        BoolPort *mOutput;
    public:
        XorNode(std::string& name): AbstractNode(name), mA(Input<BoolPort>("A")), mB(Input<BoolPort>("B")), mOutput(Output<BoolPort>("Output")) {}

        void Evaluate() override {
            mOutput->SetData(mA->GetData() != mB->GetData());
        }
    };

    class NotNode: AbstractNode {
    private:
        BoolPort *mInput;
        BoolPort *mOutput;
    public:
        NotNode(std::string& name): AbstractNode(name), mInput(Input<BoolPort>("Input")), mOutput(Output<BoolPort>("Output")) {}

        void Evaluate() override {
            mOutput->SetData(!mInput->GetData());
        }
    };
}

#endif //CUBILIGHTSTUDIO_LOGICNODES_H
