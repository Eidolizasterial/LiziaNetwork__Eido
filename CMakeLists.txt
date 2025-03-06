cmake_minimum_required(VERSION 4.0.0)

project(LiziaNetwork__Eido)

add_executable(${PROJECT_NAME} src/main.cpp 

src/LiziaNetwork/Neuron/BaseNeuron.h src/LiziaNetwork/Neuron/BaseNeuron.cpp 
src/LiziaNetwork/Neuron/DefaultNeuron.h src/LiziaNetwork/Neuron/DefaultNeuron.cpp 
src/LiziaNetwork/Neuron/IncomingNeuron.h src/LiziaNetwork/Neuron/IncomingNeuron.cpp 

src/LiziaNetwork/Layer/BaseLayer.h src/LiziaNetwork/Layer/BaseLayer.cpp 
src/LiziaNetwork/Layer/IncomingLayer.h src/LiziaNetwork/Layer/IncomingLayer.cpp 
src/LiziaNetwork/Layer/HidenLayer.h src/LiziaNetwork/Layer/HidenLayer.cpp 
src/LiziaNetwork/Layer/OutgoingLayer.h src/LiziaNetwork/Layer/OutgoingLayer.cpp 

src/LiziaNetwork/NetworkSegment/NetworkSegment.h src/LiziaNetwork/NetworkSegment/NetworkSegment.cpp 
src/LiziaNetwork/NetworkSegment/NetworkSegmentConstructor.h src/LiziaNetwork/NetworkSegment/NetworkSegmentConstructor.cpp 

src/LiziaNetwork/Network/EventDataStructure.h
src/LiziaNetwork/Network/IncomingDataStructure.h 
src/LiziaNetwork/Network/OutgoingDataStructure.h
src/LiziaNetwork/Network/Network.h src/LiziaNetwork/Network/Network.cpp 
src/LiziaNetwork/Network/NetworkConstructor.h src/LiziaNetwork/Network/NetworkConstructor.cpp 
)