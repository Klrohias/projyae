//
// Created by twiiz on 2023/4/15.
//

#ifndef PROJYAE_ENGINE_H
#define PROJYAE_ENGINE_H

#include "../render/IRenderBackend.h"

namespace ProjYae {

    class Engine {
    public:
        void init();

        void notifyNextFrame();

        [[nodiscard]] IRenderBackend *getRenderBackend() const;

        void setRenderBackend(IRenderBackend *backend);

    private:
        IRenderBackend *_renderBackend = nullptr;
    };

} // ProjYae

#endif //PROJYAE_ENGINE_H
