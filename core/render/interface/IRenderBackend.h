//
// Created by twiiz on 2023/4/16.
//

#ifndef PROJYAE_IRENDERBACKEND_H
#define PROJYAE_IRENDERBACKEND_H

#include <memory>
#include "ICommandBuffer.h"

namespace ProjYae
{
    class IRenderBackend
    {
    public:
        virtual ~IRenderBackend();

        virtual void init();

        virtual std::unique_ptr<ICommandBuffer> getCommandBuffer();
    };

} // ProjYae

#endif //PROJYAE_IRENDERBACKEND_H
