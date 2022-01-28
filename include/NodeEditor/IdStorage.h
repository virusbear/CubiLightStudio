//
// Created by Virusbear on 28.01.2022.
//

#ifndef CUBILIGHTSTUDIO_IDSTORAGE_H
#define CUBILIGHTSTUDIO_IDSTORAGE_H

#include <vector>
#include <hash_map>
#include <imnodes.h>

namespace CubiLight {
    struct IdPool {
        std::vector<bool> NodeIds;
        std::vector<bool> PortIds;
        std::vector<bool> LinkIds;
    };

    class IdStorage {
    public:
        static int NewNodeId(ImNodesContext *ctx = ImNodes::GetCurrentContext()) {
            return NewIdInPool(GetPoolForContext(ctx)->NodeIds);
        }

        static int NewPortId(ImNodesContext *ctx = ImNodes::GetCurrentContext()) {
            return NewIdInPool(GetPoolForContext(ctx)->PortIds);
        }
        static int NewLinkId(ImNodesContext *ctx = ImNodes::GetCurrentContext()) {
            return NewIdInPool(GetPoolForContext(ctx)->LinkIds);
        }

        static void FreeNodeId(int id, ImNodesContext *ctx = ImNodes::GetCurrentContext()) {
            FreeIdInPool(id, GetPoolForContext(ctx)->NodeIds);
        }
        static void FreePortId(int id, ImNodesContext *ctx = ImNodes::GetCurrentContext()) {
            FreeIdInPool(id, GetPoolForContext(ctx)->PortIds);
        }
        static void FreeLinkId(int id, ImNodesContext *ctx = ImNodes::GetCurrentContext()) {
            FreeIdInPool(id, GetPoolForContext(ctx)->LinkIds);
        }

        static void FreeContext(ImNodesContext *ctx = ImNodes::GetCurrentContext()) {
            delete GetPoolForContext(ctx);

            m_storage.erase(ctx);
        }
    private:
        static int NewIdInPool(std::vector<bool>& pool) {
            auto idx = std::find(pool.begin(), pool.end(), false);

            if(idx == pool.end()) {
                pool.push_back(true);
                return (int) (pool.end() - pool.begin() -1);
            }

            *idx = true;
            return (int) (idx - pool.begin());
        }

        static void FreeIdInPool(int id, std::vector<bool>& pool) {
            auto idx = pool.begin() + id;

            if(idx == pool.end() - 1) {
                pool.erase(idx);
            }

            if(idx >= pool.begin() && idx < pool.end()) {
                *idx = false;
            }
        }

        static IdPool *GetPoolForContext(ImNodesContext *ctx) {
            IdPool *pool;
            if(m_storage.find(ctx) == m_storage.end()) {
                pool = new IdPool;
                m_storage[ctx] = pool;
            } else {
                pool = m_storage[ctx];
            }

            return pool;
        }
    private:
        static std::unordered_map<ImNodesContext *, IdPool *> m_storage;
    };
}

#endif //CUBILIGHTSTUDIO_IDSTORAGE_H
