//
// Created by Virusbear on 29.01.2022.
//

#ifndef CUBILIGHTSTUDIO_TYPE_H
#define CUBILIGHTSTUDIO_TYPE_H

#include <string>
#include <stack>

namespace CubiLight {
    struct Type {
        Type() noexcept = default;
        Type(Type *parent, std::string type) noexcept: parent(parent), type(type), m_inverse(Invert()) { }
        std::stack<Type *> Inverse() const { return m_inverse; }
        const Type *parent = nullptr;
        const std::string type;
    private:
        std::stack<Type *> Invert() {
            std::stack<Type *> inverse;
            Type *currType = this;

            while(currType != nullptr) {
                inverse.push(currType);
                currType = (Type *)currType->parent;
            }

            return inverse;
        }
        std::stack<Type *> m_inverse;
    };
}

#endif //CUBILIGHTSTUDIO_TYPE_H
