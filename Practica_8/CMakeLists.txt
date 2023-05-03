cmake_minimum_required(VERSION 3.19)
project(prueba)

set(CMAKE_CXX_STANDARD 20)

FILE(GLOB SOURCE_FILES *.cpp)

ADD_EXECUTABLE(a.exe ${SOURCE_FILES} ItemApilable.h ItemApilable.cpp Espada.h Espada.cpp Filete.h Filete.cpp Bloque.h Bloque.cpp EmptyContainer.h)
