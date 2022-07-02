//
// Created by faf on 28.06.2022.
//

#include "BasePort.h"

namespace CubiLight {
    template <typename T>
    void BasePort<T>::SetData(T value) {
        *mData = value;
    }

    template <typename T>
    void BasePort<T>::LinkFrom(Port &other) {
        auto port = dynamic_cast<BasePort<T> *>(&other);

        if(port == nullptr) {
            return;
        }

        mData = port->data;
    }

    template <typename T>
    void BasePort<T>::Unlink() {
        mData = nullptr;
    }

    template <typename T>
    const T& BasePort<T>::GetData() {
        if(mData == nullptr) {
            return mDefault;
        } else {
            return *mData;
        }
    }
}