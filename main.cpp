#include "Domain/Array/Array.h"
#include "UserInterface/Console.h"
#include "Tests/TestAll/TestAll.h"

int main() {
    TestAll test;
    test.run();

    UserRepositoryCSV userRepository("users.csv");
    UserService userService(userRepository);
    Console console(userService);

    console.runMenu();
    return 0;
}
