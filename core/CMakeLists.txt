# macros

set(PLATFORM_SOURCE "")
if (PROJYAE_DARWIN)
    add_compile_definitions(PROJYAE_METAL_ENABLE)
    set(PLATFORM_SOURCE backends/metal/MetalBackend.mm)
else()
    add_compile_definitions(PROJYAE_VULKAN_ENABLE)
    add_compile_definitions(PROJYAE_OPENGL_ENABLE)
    find_package(glad CONFIG REQUIRED)

    set(PLATFORM_SOURCE backends/opengl/GlBackend.cpp)
endif()



# compile
add_library(ProjYae ${PLATFORM_SOURCE} engine/Engine.cpp backends/IRenderBackend.cpp)

if (PROJYAE_DARWIN)
    target_link_libraries(ProjYae PRIVATE
            "-framework Foundation"
            "-framework QuartzCore"
            "-framework Metal"
            "-framework MetalKit")
else()
    target_link_libraries(ProjYae PRIVATE glad::glad)
endif()
