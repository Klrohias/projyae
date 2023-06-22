//
// Created by Twiiz on 2023/5/2.
//

#include "GlBackend.hpp"
#include "GlCommandBuffer.h"
#include <glad/glad.h>

namespace ProjYae
{
    void GlBackend::setupGl(void* getProcAddr)
    {
        gladLoadGLLoader(reinterpret_cast<GLADloadproc>(getProcAddr));
    }

    void GlBackend::draw()
    {
        std::lock_guard<std::mutex> lock(_sharedCommandBuffer.commandWriteLock);

        for (const GlRenderCommand& cmd : _sharedCommandBuffer.commands) {
            executeCommand(cmd);
        }

        _sharedCommandBuffer.commands.clear();
    }

    std::unique_ptr<ICommandBuffer> GlBackend::getCommandBuffer()
    {
        return std::make_unique<GlCommandBuffer>(&_sharedCommandBuffer);
    }

    void GlBackend::executeCommand(const GlRenderCommand& renderCommand)
    {
        switch (renderCommand.commandType)
        {
        case DRAW_MESH:
        {
            // glCreate
            break;
        }
        }
    }
}