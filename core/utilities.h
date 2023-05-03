//
// Created by Twiiz on 2023/5/2.
//

#ifndef PROJYAE_UTILITIES_H
#define PROJYAE_UTILITIES_H

#ifdef __OBJC__
#define __OBJC_TYPE(x) x
#define __OBJC_ID(x) id<x>
#define __OBJC_TYPE_PTR(x) __OBJC_TYPE(x) *
#define __OBJC_NIL Nil
#else
#define __OBJC_TYPE(x) void
#define __OBJC_ID(x) void *
#define __OBJC_TYPE_PTR(x) __OBJC_TYPE(x) *
#define __OBJC_NIL nullptr
#endif

#define __UNUSED_PTR(x) (void*)(x)

#endif //PROJYAE_UTILITIES_H
