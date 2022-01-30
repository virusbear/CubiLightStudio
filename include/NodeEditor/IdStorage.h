//
// Created by Virusbear on 28.01.2022.
//

#ifndef CUBILIGHTSTUDIO_IDSTORAGE_H
#define CUBILIGHTSTUDIO_IDSTORAGE_H

#include <vector>
#include <unordered_map>
#include <imnodes.h>

namespace CubiLight {
    struct IdPool {
        std::vector<bool> NodeIds;
        std::vector<bool> PortIds;
        std::vector<bool> LinkIds;
    };

    class IdStorage {
    public:
        static int NewNodeId(ImNodesContext *ctx = ImNodes::GetCurrentContext());
        static int NewPortId(ImNodesContext *ctx = ImNodes::GetCurrentContext());
        static int NewLinkId(ImNodesContext *ctx = ImNodes::GetCurrentContext());
        static void FreeNodeId(int id, ImNodesContext *ctx = ImNodes::GetCurrentContext());
        static void FreePortId(int id, ImNodesContext *ctx = ImNodes::GetCurrentContext());
        static void FreeLinkId(int id, ImNodesContext *ctx = ImNodes::GetCurrentContext());
        static void FreeContext(ImNodesContext *ctx = ImNodes::GetCurrentContext());
    private:
        static int NewIdInPool(std::vector<bool>& pool);
        static void FreeIdInPool(int id, std::vector<bool>& pool);
        static IdPool *GetPoolForContext(ImNodesContext *ctx);
    private:
        static std::unordered_map<ImNodesContext *, IdPool *> m_storage;
    };
}

#endif //CUBILIGHTSTUDIO_IDSTORAGE_H
