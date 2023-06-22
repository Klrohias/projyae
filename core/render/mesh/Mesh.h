//
// Created by Twiiz on 2023/5/13.
//

#ifndef PROJYAE_MESH_H
#define PROJYAE_MESH_H

#include <vector>

namespace ProjYae
{

    class Mesh
    {
        std::vector<float> _vertices;
        std::vector<uint32_t> _indices;

    public:
        [[nodiscard]] float* getVerticesBuffer();

        std::vector<float>& getVertices();

        uint32_t* getIndicesBuffer();

        std::vector<uint32_t>& getIndices();

        union {
            void* renderBackendParameterPointer = nullptr;
            int renderBackendParameterInt32;
            long renderBackendParameterInt64;
        };
    };

} // ProjYae

#endif //PROJYAE_MESH_H
