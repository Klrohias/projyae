//
// Created by Twiiz on 2023/5/13.
//

#ifndef PROJYAE_GLCOMMANDBUFFER_H
#define PROJYAE_GLCOMMANDBUFFER_H

#include "../interface/ICommandBuffer.h"
#include "SharedCommandBuffer.h"

namespace ProjYae
{

    class GlCommandBuffer : public ICommandBuffer
    {
        SharedCommandBuffer* const _sharedCommandBuffer;
    public:
        explicit GlCommandBuffer(SharedCommandBuffer* commandBuffer);

        void end() override;

        void drawMesh(ProjYae::Mesh &mesh) override;
    };

} // ProjYae

#endif //PROJYAE_GLCOMMANDBUFFER_H
