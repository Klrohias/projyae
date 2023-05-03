# Configure / Packages
set(PLATFORM_SOURCE "")
if (PROJYAE_DARWIN)
    add_compile_definitions(PROJYAE_METAL_ENABLE)
    set(PLATFORM_SOURCE render/metal/MetalBackend.mm)
else()
    add_compile_definitions(PROJYAE_VULKAN_ENABLE)
    add_compile_definitions(PROJYAE_OPENGL_ENABLE)
    find_package(glad CONFIG REQUIRED)

    set(PLATFORM_SOURCE render/opengl/GlBackend.cpp)
endif()

find_path(MINIAUDIO_INCLUDE_DIRS "miniaudio.h")
find_path(DRLIBS_INCLUDE_DIRS "dr_flac.h") # dr_mp3/wav.h is in same as dr_flac.h
find_package(Stb REQUIRED)

# Build
add_library(ProjYae ${PLATFORM_SOURCE} engine/Engine.cpp render/IRenderBackend.cpp audio/miniaudio.c audio/miniaudio.h
        audio/AudioPlayer.cpp audio/AudioPlayer.h audio/IAudioStream.cpp audio/IAudioStream.h audio/drlibs.h audio/drlibs.c
        audio/stbvorbis.c audio/stbvorbis.h audio/WavAudioStream.cpp audio/WavAudioStream.h audio/Mp3AudioStream.cpp
        audio/Mp3AudioStream.h audio/FlacAudioStream.cpp audio/FlacAudioStream.h)

# Link
target_include_directories(ProjYae PRIVATE ${MINIAUDIO_INCLUDE_DIRS})
target_include_directories(ProjYae PRIVATE ${DRLIBS_INCLUDE_DIRS})
target_include_directories(ProjYae PRIVATE ${Stb_INCLUDE_DIR})

if (PROJYAE_DARWIN)
    target_link_libraries(ProjYae PRIVATE
            "-framework Foundation"
            "-framework QuartzCore"
            "-framework Metal"
            "-framework MetalKit")
else()
    target_link_libraries(ProjYae PRIVATE glad::glad)
endif()
