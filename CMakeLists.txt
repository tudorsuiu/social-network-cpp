cmake_minimum_required(VERSION 3.21)
project(proiect_sda)

set(CMAKE_CXX_STANDARD 14)

add_executable(proiect_sda main.cpp Domain/Array/Array.h Domain/BSC/BST.h Domain/BSC/BSTNode.h Domain/User/User.cpp Domain/User/User.h Repository/UserRepository/UserRepositoryCSV.cpp Repository/UserRepository/UserRepositoryCSV.h Service/UserService/UserService.cpp Service/UserService/UserService.h UserInterface/Console.cpp UserInterface/Console.h)
