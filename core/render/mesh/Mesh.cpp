//
// Created by Twiiz on 2023/5/13.
//

#include "Mesh.h"

namespace ProjYae
{
    float* Mesh::getVerticesBuffer()
    {
        return _vertices.data();
    }

    std::vector<float>& Mesh::getVertices()
    {
        return _vertices;
    }

    uint32_t* Mesh::getIndicesBuffer()
    {
        return _indices.data();
    }

    std::vector<uint32_t>& Mesh::getIndices()
    {
        return _indices;
    }
} // ProjYae