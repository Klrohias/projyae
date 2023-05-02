//
// Created by twiiz on 2023/4/16.
//

#ifndef PROJYAE_RENDERBACKEND_H
#define PROJYAE_RENDERBACKEND_H

namespace ProjYae {

    class RenderBackend {
    public:
        virtual ~RenderBackend();
        virtual void init();
    };

} // ProjYae

#endif //PROJYAE_RENDERBACKEND_H
