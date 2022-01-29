//
// Created by Virusbear on 29.01.2022.
//

#ifndef CUBILIGHTSTUDIO_TYPE_H
#define CUBILIGHTSTUDIO_TYPE_H

#include <string>

namespace CubiLight {
    struct Type {
        Type() noexcept = default;
        Type(Type *parent, std::string type) noexcept: parent(parent), type(type) { }
        const Type *parent = nullptr;
        const std::string type;
    };
}

#endif //CUBILIGHTSTUDIO_TYPE_H
