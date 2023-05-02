//
// Created by twiiz on 2023/4/15.
//

#ifndef PROJYAE_ENGINE_H
#define PROJYAE_ENGINE_H

#include "../backends/RenderBackend.h"

namespace ProjYae {

    class Engine {
    public:
        void init();

        void notifyNextFrame();

        [[nodiscard]] RenderBackend* getRenderBackend() const;

        void setRenderBackend(RenderBackend* backend);

    private:
        RenderBackend *_renderBackend = nullptr;
    };

} // ProjYae

#endif //PROJYAE_ENGINE_H
