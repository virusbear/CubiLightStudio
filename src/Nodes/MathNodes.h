//
// Created by Virusbear on 02.07.2022.
//

#ifndef CUBILIGHTSTUDIO_MATHNODES_H
#define CUBILIGHTSTUDIO_MATHNODES_H

#include "AbstractNode.h"
#include "PrimitivePorts.h"
#include "StructPorts.h"
#include <cmath>

namespace CubiLight {
    class AddNode: AbstractNode {
    private:
        FloatPort *mA;
        FloatPort *mB;
        FloatPort *mOutput;
    public:
        AddNode(std::string& name): AbstractNode(name), mA(Input<FloatPort>("A")), mB(Input<FloatPort>("B")), mOutput(Output<FloatPort>("Output")) {}

        void Evaluate() override {
            mOutput->SetData(mA->GetData() + mB->GetData());
        }
    };

    class SubtractNode: AbstractNode {
    private:
        FloatPort *mA;
        FloatPort *mB;
        FloatPort *mOutput;
    public:
        SubtractNode(std::string& name): AbstractNode(name), mA(Input<FloatPort>("A")), mB(Input<FloatPort>("B")), mOutput(Output<FloatPort>("Output")) {}

        void Evaluate() override {
            mOutput->SetData(mA->GetData() - mB->GetData());
        }
    };

    class MultiplyNode: AbstractNode {
    private:
        FloatPort *mA;
        FloatPort *mB;
        FloatPort *mOutput;
    public:
        MultiplyNode(std::string& name): AbstractNode(name), mA(Input<FloatPort>("A")), mB(Input<FloatPort>("B")), mOutput(Output<FloatPort>("Output")) {}

        void Evaluate() override {
            mOutput->SetData(mA->GetData() * mB->GetData());
        }
    };

    class DivideNode: AbstractNode {
    private:
        FloatPort *mA;
        FloatPort *mB;
        FloatPort *mOutput;
    public:
        DivideNode(std::string& name): AbstractNode(name), mA(Input<FloatPort>("A")), mB(Input<FloatPort>("B")), mOutput(Output<FloatPort>("Output")) {}

        void Evaluate() override {
            mOutput->SetData(mA->GetData() / mB->GetData());
        }
    };

    class ModuloNode: AbstractNode {
    private:
        IntPort *mA;
        IntPort *mB;
        IntPort *mOutput;
    public:
        ModuloNode(std::string& name): AbstractNode(name), mA(Input<IntPort>("A")), mB(Input<IntPort>("B")), mOutput(Output<IntPort>("Output")) {}

        void Evaluate() override {
            mOutput->SetData(mA->GetData() % mB->GetData());
        }
    };

    class FloorNode: AbstractNode {
    private:
        FloatPort *mInput;
        FloatPort *mOutput;
    public:
        FloorNode(std::string& name): AbstractNode(name), mInput(Input<FloatPort>("Input")), mOutput(Output<FloatPort>("Output")) {}

        void Evaluate() override {
            mOutput->SetData(floor(mInput->GetData()));
        }
    };

    class CeilNode: AbstractNode {
    private:
        FloatPort *mInput;
        FloatPort *mOutput;
    public:
        CeilNode(std::string& name): AbstractNode(name), mInput(Input<FloatPort>("Input")), mOutput(Output<FloatPort>("Output")) {}

        void Evaluate() override {
            mOutput->SetData(ceil(mInput->GetData()));
        }
    };

    class PowNode: AbstractNode {
    private:
        FloatPort *mBase;
        FloatPort *mExp;
        FloatPort *mOutput;
    public:
        PowNode(std::string& name): AbstractNode(name), mBase(Input < FloatPort > ("Base")), mExp(Input < FloatPort > ("Exp")), mOutput(Output < FloatPort > ("Output")) {}

        void Evaluate() override {
            mOutput->SetData(pow(mBase->GetData(), mExp->GetData()));
        }
    };
}

#endif //CUBILIGHTSTUDIO_MATHNODES_H
