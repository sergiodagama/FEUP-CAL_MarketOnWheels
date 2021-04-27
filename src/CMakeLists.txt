cmake_minimum_required(VERSION 3.17)
project(src)

set(CMAKE_CXX_STANDARD 14)

add_executable(src main.cpp Client/Client.cpp Client/Client.h Headquarter/Headquarter.cpp Headquarter/Headquarter.h Map/Map.cpp Map/Map.h Order/Order.cpp Order/Order.h Product/Product.cpp Product/Product.h Provider/Provider.cpp Provider/Provider.h Truck/Truck.cpp Truck/Truck.h Interface/Interface.cpp Interface/Interface.h Utils/Date.cpp Utils/Date.h Utils/Graph.h)