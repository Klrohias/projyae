//
// Created by twiiz on 2023/4/16.
//

#ifndef PROJYAE_IRENDERBACKEND_H
#define PROJYAE_IRENDERBACKEND_H

namespace ProjYae {

    class IRenderBackend {
    public:
        virtual ~IRenderBackend();
        virtual void init();
    };

} // ProjYae

#endif //PROJYAE_IRENDERBACKEND_H
