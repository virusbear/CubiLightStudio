//
// Created by Virusbear on 28.01.2022.
//

#include "Panels/NodeEditor/IdStorage.h"
#include <algorithm>

namespace CubiLight {
    std::unordered_map<ImNodesContext *, IdPool *> IdStorage::m_storage;

    int IdStorage::NewNodeId(ImNodesContext *ctx) {
        return NewIdInPool(GetPoolForContext(ctx)->NodeIds);
    }

    int IdStorage::NewPortId(ImNodesContext *ctx) {
        return NewIdInPool(GetPoolForContext(ctx)->PortIds);
    }

    int IdStorage::NewLinkId(ImNodesContext *ctx) {
        return NewIdInPool(GetPoolForContext(ctx)->LinkIds);
    }

    void IdStorage::FreeNodeId(int id, ImNodesContext *ctx) {
        FreeIdInPool(id, GetPoolForContext(ctx)->NodeIds);
    }

    void IdStorage::FreePortId(int id, ImNodesContext *ctx) {
        FreeIdInPool(id, GetPoolForContext(ctx)->PortIds);
    }

    void IdStorage::FreeLinkId(int id, ImNodesContext *ctx) {
        FreeIdInPool(id, GetPoolForContext(ctx)->LinkIds);
    }

    void IdStorage::FreeContext(ImNodesContext *ctx) {
        delete GetPoolForContext(ctx);

        m_storage.erase(ctx);
    }

    int IdStorage::NewIdInPool(std::vector<bool>& pool) {
        auto idx = std::find(pool.begin(), pool.end(), false);

        if(idx == pool.end()) {
            pool.push_back(true);
            return (int) (pool.end() - pool.begin() -1);
        }

        *idx = true;
        return (int) (idx - pool.begin());
    }

    void IdStorage::FreeIdInPool(int id, std::vector<bool>& pool) {
        auto idx = pool.begin() + id;

        if(idx == pool.end() - 1) {
            pool.erase(idx);
        }

        if(idx >= pool.begin() && idx < pool.end()) {
            *idx = false;
        }
    }

    IdPool *IdStorage::GetPoolForContext(ImNodesContext *ctx) {
        IdPool *pool;
        if(m_storage.find(ctx) == m_storage.end()) {
            pool = new IdPool;
            m_storage[ctx] = pool;
        } else {
            pool = m_storage[ctx];
        }

        return pool;
    }
}