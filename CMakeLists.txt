cmake_minimum_required(VERSION 4.0.0)

project(LiziaNetwork__Eido)

add_executable(${PROJECT_NAME} src/main.cpp 

src/LiziaNetwork/Layer/BaseLayer.h src/LiziaNetwork/Layer/BaseLayer.cpp 
src/LiziaNetwork/Layer/IncomingLayer.h src/LiziaNetwork/Layer/IncomingLayer.cpp 
src/LiziaNetwork/Layer/HidenLayer.h src/LiziaNetwork/Layer/HidenLayer.cpp)