//
// Created by Twiiz on 2023/5/13.
//

#ifndef PROJYAE_ICOMMANDBUFFER_H
#define PROJYAE_ICOMMANDBUFFER_H

#include "../mesh/Mesh.h"

namespace ProjYae
{
    class ICommandBuffer
    {
    public:
        virtual void end();

        virtual void drawMesh(Mesh& mesh);
    };
}

#endif //PROJYAE_ICOMMANDBUFFER_H
