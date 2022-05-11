cmake_minimum_required(VERSION 3.21)
project(proiect_sda)

set(CMAKE_CXX_STANDARD 14)

add_executable(proiect_sda main.cpp Domain/Array/Array.h Domain/BST/BST.h Domain/BST/BSTNode.h Domain/User/User.cpp Domain/User/User.h Repository/UserRepository/UserRepositoryCSV.cpp Repository/UserRepository/UserRepositoryCSV.h Service/UserService/UserService.cpp Service/UserService/UserService.h UserInterface/Console.cpp UserInterface/Console.h Tests/TestDomain/TestUser/TestUser.cpp Tests/TestDomain/TestUser/TestUser.h Tests/TestAll/TestAll.cpp Tests/TestAll/TestAll.h Tests/TestRepository/TestUserRepository/TestUserRepository.cpp Tests/TestRepository/TestUserRepository/TestUserRepository.h Tests/TestService/TestUserService/TestUserService.cpp Tests/TestService/TestUserService/TestUserService.h Tests/TestDomain/TestArray/TestArray.cpp Tests/TestDomain/TestArray/TestArray.h Domain/Event/Event.cpp Domain/Event/Event.h Domain/Message/Message.cpp Domain/Message/Message.h Domain/Friendship/Friendship.cpp Domain/Friendship/Friendship.h)
