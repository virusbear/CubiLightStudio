//
// Created by faf on 28.06.2022.
//

#include "BasePort.h"

namespace CubiLight {
    template <typename T>
    void BasePort<T>::SetDefault(T& value) {
        defaultValue = value;
    }

    template <typename T>
    void BasePort<T>::LinkFrom(Port &other) {
        auto port = dynamic_cast<BasePort<T> *>(&other);

        if(port == nullptr) {
            return;
        }

        data = port->data;
    }

    template <typename T>
    void BasePort<T>::Unlink() {
        data = nullptr;
    }

    template <typename T>
    T& BasePort<T>::GetData() {
        if(data == nullptr) {
            return defaultValue;
        } else {
            return *data;
        }
    }
}