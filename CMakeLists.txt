cmake_minimum_required(VERSION 3.15)
project(searching-algorithms-server)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)

add_executable(searching-algorithms-server main.cpp Solver.h Server.h MyTestClientHandler.cpp MyTestClientHandler.h
        ClientHandler.h CacheManager.h FileCacheManager.cpp FileCacheManager.h StringReverser.cpp StringReverser.h)