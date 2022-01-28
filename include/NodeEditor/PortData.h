//
// Created by Virusbear on 28.01.2022.
//

#ifndef CUBILIGHTSTUDIO_PORTDATA_H
#define CUBILIGHTSTUDIO_PORTDATA_H

#include <imgui.h>

namespace CubiLight {
    class PortData {
    public:
        virtual ~PortData() = default;
        virtual void Render() = 0;
    };

    struct BoolPortData: public PortData {
        BoolPortData(): Value(false) {}
        bool Value;

        void Render() override {
            ImGui::Checkbox("##hidden", &Value);
        }
    };

}

#endif //CUBILIGHTSTUDIO_PORTDATA_H
