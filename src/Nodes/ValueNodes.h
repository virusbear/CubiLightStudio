//
// Created by Virusbear on 02.07.2022.
//

#ifndef CUBILIGHTSTUDIO_VALUENODES_H
#define CUBILIGHTSTUDIO_VALUENODES_H

#include "AbstractNode.h"
#include "PrimitivePorts.h"

namespace CubiLight {
    template <typename T>
    class ValueNode: AbstractNode {
    private:
        T *mInput;
        T *mOutput;
    public:
        ValueNode(std::string& name): AbstractNode(name), mInput(Input<T>("Input")), mOutput(Output<T>("Output")) { }

        void Evaluate() override {
            mOutput->SetData(mInput->GetData());
        }
    };

    typedef ValueNode<BoolPort> BoolNode;
    typedef ValueNode<UBytePort> UByteNode;
    typedef ValueNode<UShortPort> UShortNode;
    typedef ValueNode<UIntPort> UIntNode;
    typedef ValueNode<ULongPort> ULongNode;
    typedef ValueNode<BytePort> ByteNode;
    typedef ValueNode<ShortPort> ShortNode;
    typedef ValueNode<IntPort> IntNode;
    typedef ValueNode<LongPort> LongNode;
    typedef ValueNode<FloatPort> FloatNode;
    typedef ValueNode<DoublePort> DoubleNode;
    typedef ValueNode<StringPort> StringNode;
}

#endif //CUBILIGHTSTUDIO_VALUENODES_H
