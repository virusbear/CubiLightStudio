//
// Created by Virusbear on 02.07.2022.
//

#ifndef CUBILIGHTSTUDIO_VECTORNODES_H
#define CUBILIGHTSTUDIO_VECTORNODES_H

#include "AbstractNode.h"
#include "../Math/IVec2.h"
#include "../Math/IVec3.h"
#include "../Math/Vec2.h"
#include "../Math/Vec3.h"
#include "../Math/Color.h"
#include "PrimitivePorts.h"
#include "StructPorts.h"

namespace CubiLight {
    class IVec2Node: AbstractNode {
    private:
        IntPort *mX;
        IntPort *mY;
        IVec2Port *mOutput;
    public:
        IVec2Node(std::string& name): AbstractNode(name), mX(Input<IntPort>("X")), mY(Input<IntPort>("Y")), mOutput(Output<IVec2Port>("Output")) { }

        void Evaluate() override {
            mOutput->SetData(IVec2(mX->GetData(), mY->GetData()));
        }
    };

    class DecomposeIVec2Node: AbstractNode {
    private:
        IVec2Port *mInput;
        IntPort *mX;
        IntPort *mY;
    public:
        DecomposeIVec2Node(std::string& name): AbstractNode(name), mInput(Input<IVec2Port>("Input")), mX(Output<IntPort>("X")), mY(Output<IntPort>("Y")) { }

        void Evaluate() override {
            auto vec = mInput->GetData();
            mX->SetData(vec.x);
            mY->SetData(vec.y);
        }
    };

    class IVec3Node: AbstractNode {
    private:
        IntPort *mX;
        IntPort *mY;
        IntPort *mZ;
        IVec3Port *mOutput;
    public:
        IVec3Node(std::string& name): AbstractNode(name), mX(Input<IntPort>("X")), mY(Input<IntPort>("Y")), mZ(Input<IntPort>("Z")), mOutput(Output<IVec3Port>("Output")) { }

        void Evaluate() override {
            mOutput->SetData(IVec3(mX->GetData(), mY->GetData(), mZ->GetData()));
        }
    };

    class DecomposeIVec3Node: AbstractNode {
    private:
        IVec3Port *mInput;
        IntPort *mX;
        IntPort *mY;
        IntPort *mZ;
    public:
        DecomposeIVec3Node(std::string& name): AbstractNode(name), mInput(Input<IVec3Port>("Input")), mX(Output<IntPort>("X")), mY(Output<IntPort>("Y")), mZ(Output<IntPort>("Z")) { }

        void Evaluate() override {
            auto vec = mInput->GetData();
            mX->SetData(vec.x);
            mY->SetData(vec.y);
            mZ->SetData(vec.z);
        }
    };

    class Vec2Node: AbstractNode {
    private:
        FloatPort *mX;
        FloatPort *mY;
        Vec2Port *mOutput;
    public:
        Vec2Node(std::string& name): AbstractNode(name), mX(Input<FloatPort>("X")), mY(Input<FloatPort>("Y")), mOutput(Output<Vec2Port>("Output")) { }

        void Evaluate() override {
            mOutput->SetData(Vec2(mX->GetData(), mY->GetData()));
        }
    };

    class DecomposeVec2Node: AbstractNode {
    private:
        Vec2Port *mInput;
        FloatPort *mX;
        FloatPort *mY;
    public:
        DecomposeVec2Node(std::string& name): AbstractNode(name), mInput(Input<Vec2Port>("Input")), mX(Output<FloatPort>("X")), mY(Output<FloatPort>("Y")) { }

        void Evaluate() override {
            auto vec = mInput->GetData();
            mX->SetData(vec.x);
            mY->SetData(vec.y);
        }
    };

    class Vec3Node: AbstractNode {
    private:
        FloatPort *mX;
        FloatPort *mY;
        FloatPort *mZ;
        Vec3Port *mOutput;
    public:
        Vec3Node(std::string& name): AbstractNode(name), mX(Input<FloatPort>("X")), mY(Input<FloatPort>("Y")), mZ(Input<FloatPort>("Z")), mOutput(Output<Vec3Port>("Output")) { }

        void Evaluate() override {
            mOutput->SetData(Vec3(mX->GetData(), mY->GetData(), mZ->GetData()));
        }
    };

    class DecomposeVec3Node: AbstractNode {
    private:
        Vec3Port *mInput;
        FloatPort *mX;
        FloatPort *mY;
        FloatPort *mZ;
    public:
        DecomposeVec3Node(std::string& name): AbstractNode(name), mInput(Input<Vec3Port>("Input")), mX(Output<FloatPort>("X")), mY(Output<FloatPort>("Y")), mZ(Output<FloatPort>("Z")) { }

        void Evaluate() override {
            auto vec = mInput->GetData();
            mX->SetData(vec.x);
            mY->SetData(vec.y);
            mZ->SetData(vec.z);
        }
    };

    class ColorNode: AbstractNode {
    private:
        FloatPort *mR;
        FloatPort *mG;
        FloatPort *mB;
        FloatPort *mA;
        ColorPort *mOutput;
    public:
        ColorNode(std::string& name): AbstractNode(name), mR(Input<FloatPort>("R")), mG(Input<FloatPort>("G")), mB(Input<FloatPort>("B")), mA(Input<FloatPort>("A")), mOutput(Output<ColorPort>("Output")) { }

        void Evaluate() override {
            mOutput->SetData(Color(mR->GetData(), mG->GetData(), mB->GetData(), mA->GetData()));
        }
    };

    class DecomposeColorNode: AbstractNode {
    private:
        ColorPort *mInput;
        FloatPort *mR;
        FloatPort *mG;
        FloatPort *mB;
        FloatPort *mA;
    public:
        DecomposeColorNode(std::string& name): AbstractNode(name), mInput(Input<ColorPort>("Input")), mR(Output<FloatPort>("R")), mG(Output<FloatPort>("G")), mB(Output<FloatPort>("B")), mA(Output<FloatPort>("A")) { }

        void Evaluate() override {
            auto color = mInput->GetData();
            mR->SetData(color.r);
            mG->SetData(color.g);
            mB->SetData(color.b);
            mA->SetData(color.a);
        }
    };
}

#endif //CUBILIGHTSTUDIO_VECTORNODES_H
