//
// Created by Twiiz on 2023/5/13.
//

#ifndef PROJYAE_SHAREDCOMMANDBUFFER_H
#define PROJYAE_SHAREDCOMMANDBUFFER_H

#include <mutex>
#include <vector>
#include "../mesh/Mesh.h"

namespace ProjYae
{
    enum GlRenderCommandType
    {
        DRAW_MESH,
    };
    struct GlRenderCommand
    {
        GlRenderCommandType commandType;
        union
        {
            struct
            {
                Mesh* mesh;
            } drawMeshParameter;
        };
    };
    struct SharedCommandBuffer
    {
        std::mutex commandWriteLock;
        std::vector<GlRenderCommand> commands;
    };
}


#endif //PROJYAE_SHAREDCOMMANDBUFFER_H
