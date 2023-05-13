cmake_minimum_required(VERSION 3.21)
project(CloudPOO_v2)

set(CMAKE_CXX_STANDARD 20)

add_executable(cloudpoo main.cpp Generador.cpp Generador.h Dispositivo.cpp Dispositivo.h DataCenter.cpp DataCenter.h RackAlmacenamiento.h RackAlmacenamiento.cpp RackServidores.h RackServidores.cpp DataCenterException.h)
