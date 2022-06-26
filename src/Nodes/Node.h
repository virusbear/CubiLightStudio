#ifndef CUBILIGHTSTUDIO_NODE_H
#define CUBILIGHTSTUDIO_NODE_H

#include <vector>
#include <string>
#include "Port.h"

namespace CubiLight {
    class Node {
        public:
            virtual std::string GetName();
            virtual std::vector<Port *> GetPorts();
            virtual void Evaluate();
    };
}

#endif //CUBILIGHTSTUDIO_NODE_H