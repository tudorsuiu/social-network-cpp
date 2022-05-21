#include "Domain/ADT/List/List.h"
#include "UserInterface/Console/Console.h"
#include "Tests/TestAll/TestAll.h"
#include "Repository/RepositoryCSV.h"
#include "Repository/BSTRepositoryCSV.h"

int main() {
    TestAll test;
    test.run();

    RepositoryCSV<User> userRepository("users.csv");
    UserService userService(userRepository);

    BSTRepositoryCSV<Event> eventRepository("events.csv");
    EventService eventService(eventRepository, userService);

    RepositoryCSV<Friendship> friendshipRepository("friendships.csv");
    FriendshipService friendshipService(friendshipRepository, userService);

    RepositoryCSV<Message> messageRepository("messages.csv");
    MessageService messageService(messageRepository, userService);

    Network network(userService, friendshipService, messageService, eventService);

    Console console(network);

    console.run();
    return 0;
}
