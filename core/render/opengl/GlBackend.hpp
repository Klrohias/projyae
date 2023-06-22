//
// Created by Twiiz on 2023/5/2.
//

#ifndef PROJYAE_GLBACKEND_HPP
#define PROJYAE_GLBACKEND_HPP

#include <mutex>
#include "core/render/interface/IRenderBackend.h"
#include "SharedCommandBuffer.h"

namespace ProjYae
{
    class GlBackend : public IRenderBackend
    {
        SharedCommandBuffer _sharedCommandBuffer;
    public:
        static void setupGl(void* getProcAddr);

        void draw();

        std::unique_ptr<ICommandBuffer> getCommandBuffer() override;

    private:
        void executeCommand(const GlRenderCommand& renderCommand);
    };
}

#endif //PROJYAE_GLBACKEND_HPP
