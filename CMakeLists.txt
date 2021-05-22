cmake_minimum_required(VERSION 3.17)
project(MarketOnWheels)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

include_directories(src/Client)
include_directories(src/Exceptions)
include_directories(src/Headquarter)
include_directories(src/Menu)
include_directories(src/Map)
include_directories(src/Order)
include_directories(src/Product)
include_directories(src/Provider)
include_directories(src/Truck)
include_directories(src/Utils)

add_executable(MarketOnWheels
        src/Client/Client.cpp
        src/Client/Client.h
        src/Exceptions/Exceptions.cpp
        src/Exceptions/Exceptions.h
        src/Headquarter/Headquarter.cpp
        src/Headquarter/Headquarter.h
        src/Menu/Menu.cpp
        src/Menu/Menu.h
        src/Order/Order.cpp
        src/Order/Order.h
        src/Product/Product.cpp
        src/Product/Product.h
        src/Provider/Provider.cpp
        src/Provider/Provider.h
        src/Truck/Truck.cpp
        src/Truck/Truck.h
        src/Utils/Date.cpp
        src/Utils/Date.h
        src/Utils/Graph.h
        src/Utils/MutablePriorityQueue.h
        src/main.cpp
        src/Position/Position.cpp src/Position/Position.h src/Utils/Utils.cpp src/Utils/Utils.h src/ProductsWrapper/ProductsWrapper.cpp src/ProductsWrapper/ProductsWrapper.h src/Tests/Tests.cpp src/Interface/Interface.cpp src/Interface/Interface.h src/Tests/Dataset.cpp)

target_link_libraries(MarketOnWheels gtest gtest_main)