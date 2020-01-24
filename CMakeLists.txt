cmake_minimum_required(VERSION 3.15)
project(FlightSimulatorPart2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)


add_executable(searching-algorithms-server main.cpp Server.h ClientHandler.h MyTestClientHandler.cpp MyTestClientHandler.h Solver.h CacheManager.h MySerialServer.cpp MySerialServer.h StringReverser.cpp StringReverser.h FileCacheManager.cpp FileCacheManager.h MyClientHandler.cpp MyClientHandler.h ObjectAdapter.cpp ObjectAdapter.h Searcher.h Searchable.cpp Searchable.h Solution.cpp Solution.h BFS.cpp BFS.h Matrix.cpp Matrix.h)
