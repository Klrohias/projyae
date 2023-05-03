cmake_minimum_required(VERSION 3.20)
project(ProjYae)

set(CMAKE_CXX_STANDARD 23)
include_directories(./)

if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(PROJYAE_DARWIN TRUE)
endif()
if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    set(PROJYAE_WIN32 TRUE)
endif()
if (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    set(PROJYAE_LINUX TRUE)
endif()

# projects
add_subdirectory(core)

if (${PROJYAE_DARWIN})
    add_subdirectory(player-darwin)
endif()
if (${PROJYAE_WIN32} OR ${PROJYAE_LINUX})
    add_subdirectory(player-desktop)
endif()