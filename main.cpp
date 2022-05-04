#include "Domain/Array/Array.h"
#include "UserInterface/Console.h"

int main() {

    UserRepositoryCSV userRepository("users.csv");
    UserService userService(userRepository);
    Console console(userService);

    console.runMenu();
    return 0;
}
