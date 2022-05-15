#include "Domain/ADT/List/List.h"
#include "UserInterface/Console/Console.h"
#include "Tests/TestAll/TestAll.h"
#include "Repository/RepositoryCSV.h"

int main() {
    TestAll test;
    test.run();

    RepositoryCSV<User> userRepository("users.csv");
    UserService userService(userRepository);

    RepositoryCSV<Event> eventRepository("events.csv");
    EventService eventService(eventRepository, userService);

    RepositoryCSV<Friendship> friendshipRepository("friendships.csv");
    FriendshipService friendshipService(friendshipRepository, userService);

    RepositoryCSV<Message> messageRepository("messages.csv");
    MessageService messageService(messageRepository, userService);

    Console console(userService, messageService, eventService, friendshipService);

    console.runMenu();
    return 0;
}
