#include "Domain/Array/List.h"
#include "UserInterface/Console.h"
#include "Tests/TestAll/TestAll.h"
#include "Repository/RepositoryCSV.h"

int main() {
    TestAll test;
    test.run();

    RepositoryCSV<User> userRepository("users.csv");
    UserService userService(userRepository);
    Console console(userService);

    console.runMenu();
    return 0;
}
