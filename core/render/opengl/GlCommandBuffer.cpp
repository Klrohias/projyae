//
// Created by Twiiz on 2023/5/13.
//

#include "GlCommandBuffer.h"

namespace ProjYae
{
    GlCommandBuffer::GlCommandBuffer(SharedCommandBuffer* commandBuffer) : _sharedCommandBuffer(commandBuffer)
    {
    }

    void GlCommandBuffer::end()
    {
        // Nothing to do
    }

    void GlCommandBuffer::drawMesh(Mesh& mesh)
    {
        GlRenderCommand cmd{};
        cmd.commandType = DRAW_MESH;
        cmd.drawMeshParameter.mesh = &mesh;

        std::lock_guard<std::mutex> lock(_sharedCommandBuffer->commandWriteLock);
        _sharedCommandBuffer->commands.push_back(cmd);
    }
} // ProjYae