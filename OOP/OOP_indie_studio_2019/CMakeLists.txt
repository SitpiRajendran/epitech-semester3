cmake_minimum_required(VERSION 3.0.0)
project(bomberman VERSION 0.1.0)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

message(${CMAKE_MODULE_PATH})

if (WIN32)
    message("The environment is WINDOWS")
    file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build/Debug)
    set(OS WINDOWS)
elseif(UNIX)
    message("The environment is LINUX")
    set(OS UNIX)
else()
    message("OS NOT SUPPORTED")
    set(OS NOT_SUPPORTED)
endif()


find_package(Irrlicht REQUIRED)

if (Irrlicht_FOUND)
    include_directories(${Irrlicht_INCLUDE_DIRS})
endif()

if (UNIX)
    find_package(SFML REQUIRED audio)
    if(SFML_FOUND)
        include_directories(${SFML_INCLUDE_DIR})
    endif()
endif()

if (WIN32)
    set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
    find_package(SFML 2 COMPONENTS audio REQUIRED)
endif()

set(pathProject ${CMAKE_CURRENT_SOURCE_DIR})

INCLUDE_DIRECTORIES(
    ./INCLUDE_DIRECTORIES
    ${PROJECT_SOURCE_DIR}/Class
    ${PROJECT_SOURCE_DIR}/Class/Bombs
    ${PROJECT_SOURCE_DIR}/Class/ErrorHandler
    ${PROJECT_SOURCE_DIR}/Class/Events
    ${PROJECT_SOURCE_DIR}/Class/Game
    ${PROJECT_SOURCE_DIR}/Class/Graphics
    ${PROJECT_SOURCE_DIR}/Class/Map
    ${PROJECT_SOURCE_DIR}/Class/Menu
    ${PROJECT_SOURCE_DIR}/Class/Player
    ${PROJECT_SOURCE_DIR}/Class/System
    ${PROJECT_SOURCE_DIR}/Class/TitleScreen
    ${PROJECT_SOURCE_DIR}/include
)

file(GLOB SOURCES
    "src/*.cpp"
    "src/Bombs/*.cpp"
    "src/Event/*.cpp"
    "src/Game/*.cpp"
    "src/Graphics/*.cpp"
    "src/Map/*.cpp"
    "src/Menu/*.cpp"
    "src/Player/*.cpp"
    "src/System/*.cpp"
    "src/TitleScreen/*.cpp"
)

add_executable(bomberman ${SOURCES})

if (WIN32)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/Irrlicht.dll ${CMAKE_CURRENT_SOURCE_DIR}/build/Debug COPYONLY)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/SFML/bin/openal32.dll ${CMAKE_CURRENT_SOURCE_DIR}/build/Debug COPYONLY)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/SFML/bin/sfml-audio-2.dll ${CMAKE_CURRENT_SOURCE_DIR}/build/Debug COPYONLY)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/SFML/bin/sfml-audio-d-2.dll ${CMAKE_CURRENT_SOURCE_DIR}/build/Debug COPYONLY)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/SFML/bin/sfml-system-2.dll ${CMAKE_CURRENT_SOURCE_DIR}/build/Debug COPYONLY)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/SFML/bin/sfml-system-d-2.dll ${CMAKE_CURRENT_SOURCE_DIR}/build/Debug COPYONLY)
    file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/resources DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/build/Debug)
    file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/src DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/build/Debug)
    file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Class DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/build/Debug)
    if (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/out)
        configure_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/Irrlicht.dll "${CMAKE_CURRENT_SOURCE_DIR}/out/build/x64-Debug\ (par\ défaut)" COPYONLY)
        configure_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/SFML/bin/openal32.dll "${CMAKE_CURRENT_SOURCE_DIR}/out/build/x64-Debug\ (par\ défaut)" COPYONLY)
        configure_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/SFML/bin/sfml-audio-2.dll "${CMAKE_CURRENT_SOURCE_DIR}/out/build/x64-Debug\ (par\ défaut)" COPYONLY)
        configure_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/SFML/bin/sfml-audio-d-2.dll "${CMAKE_CURRENT_SOURCE_DIR}/out/build/x64-Debug\ (par\ défaut)" COPYONLY)
        configure_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/SFML/bin/sfml-system-2.dll "${CMAKE_CURRENT_SOURCE_DIR}/out/build/x64-Debug\ (par\ défaut)" COPYONLY)
        configure_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/SFML/bin/sfml-system-d-2.dll "${CMAKE_CURRENT_SOURCE_DIR}/out/build/x64-Debug\ (par\ défaut)" COPYONLY)
        file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/resources DESTINATION "${CMAKE_CURRENT_SOURCE_DIR}/out/build/x64-Debug\ (par\ défaut)")
        file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/src DESTINATION "${CMAKE_CURRENT_SOURCE_DIR}/out/build/x64-Debug\ (par\ défaut)")
        file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Class DESTINATION "${CMAKE_CURRENT_SOURCE_DIR}/out/build/x64-Debug\ (par\ défaut)")
    endif()
    target_link_libraries (bomberman "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Irrlicht.lib")
    target_link_libraries (bomberman sfml-audio)
else ()
    target_link_libraries (bomberman Irrlicht)
    target_link_libraries (bomberman sfml-audio)
endif()