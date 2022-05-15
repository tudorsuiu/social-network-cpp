//
// Created by Tudor on 5/5/2022.
//

#include "../../../Domain/Entities/User/User.h"
#include "TestUser.h"
#include <cassert>

void TestUser::constructor() {
    User user;
    assert(user.getId() == 0);
    assert(user.getFirstName().empty() == true);
    assert(user.getLastName().empty() == true);
    assert(user.getAge() == 0);
    assert(user.getEmail().empty() == true);
    assert(user.getPhoneNumber().empty() == true);
}

void TestUser::parametersConstructor() {
    User user(1, "First name", "Last name", 18, "firstname.lastname@domain.com", "parola123", "40712345678");
    assert(user.getId() == 1);
    assert(user.getFirstName() == "First name");
    assert(user.getLastName() == "Last name");
    assert(user.getAge() == 18);
    assert(user.getEmail() == "firstname.lastname@domain.com");
    assert(user.getPhoneNumber() == "40712345678");
}

void TestUser::lineConstructor() {
    User user("1,First name,Last name,18,firstname.lastname@domain.com,parola123,40712345678", ',');
    assert(user.getId() == 1);
    assert(user.getFirstName() == "First name");
    assert(user.getLastName() == "Last name");
    assert(user.getAge() == 18);
    assert(user.getEmail() == "firstname.lastname@domain.com");
    assert(user.getPhoneNumber() == "40712345678");
}

void TestUser::copyConstructor() {
    User user(1, "First name", "Last name", 18, "firstname.lastname@domain.com", "parola123", "40712345678");
    User copyUser = user;
    assert(copyUser.getId() == 1);
    assert(copyUser.getFirstName() == "First name");
    assert(copyUser.getLastName() == "Last name");
    assert(copyUser.getAge() == 18);
    assert(copyUser.getEmail() == "firstname.lastname@domain.com");
    assert(copyUser.getPhoneNumber() == "40712345678");
}

void TestUser::getId() {
    User user(1, "First name", "Last name", 18, "firstname.lastname@domain.com", "parola123", "40712345678");
    assert(user.getId() == 1);
}

void TestUser::setId() {
    User user(1, "First name", "Last name", 18, "firstname.lastname@domain.com", "parola123", "40712345678");
    user.setId(2);
    assert(user.getId() == 2);
}

void TestUser::getFirstName() {
    User user(1, "First name", "Last name", 18, "firstname.lastname@domain.com", "parola123", "40712345678");
    assert(user.getFirstName() == "First name");
}

void TestUser::setFirstName() {
    User user(1, "First name", "Last name", 18, "firstname.lastname@domain.com", "parola123", "40712345678");
    user.setFirstName("First test");
    assert(user.getFirstName() == "First test");
}

void TestUser::getLastName() {
    User user(1, "First name", "Last name", 18, "firstname.lastname@domain.com", "parola123", "40712345678");
    assert(user.getLastName() == "Last name");
}

void TestUser::setLastName() {
    User user(1, "First name", "Last name", 18, "firstname.lastname@domain.com", "parola123", "40712345678");
    user.setLastName("Last test");
    assert(user.getLastName() == "Last test");
}

void TestUser::getAge() {
    User user(1, "First name", "Last name", 18, "firstname.lastname@domain.com", "parola123", "40712345678");
    assert(user.getAge() == 18);
}

void TestUser::setAge() {
    User user(1, "First name", "Last name", 18, "firstname.lastname@domain.com", "parola123", "40712345678");
    user.setAge(19);
    assert(user.getAge() == 19);
}

void TestUser::getEmail() {
    User user(1, "First name", "Last name", 18, "firstname.lastname@domain.com", "parola123", "40712345678");
    assert(user.getEmail() == "firstname.lastname@domain.com");
}

void TestUser::setEmail() {
    User user(1, "First name", "Last name", 18, "firstname.lastname@domain.com", "parola123", "40712345678");
    user.setEmail("firsttest.lasttest@domain.com");
    assert(user.getEmail() == "firsttest.lasttest@domain.com");
}

void TestUser::getPhoneNumber() {
    User user(1, "First name", "Last name", 18, "firstname.lastname@domain.com", "parola123", "40712345678");
    assert(user.getPhoneNumber() == "40712345678");
}

void TestUser::setPhoneNumber() {
    User user(1, "First name", "Last name", 18, "firstname.lastname@domain.com", "parola123", "40712345678");
    user.setPhoneNumber("40723456789");
    assert(user.getPhoneNumber() == "40723456789");
}

void TestUser::verifyPassword() {
    User user(1, "First name", "Last name", 18, "firstname.lastname@domain.com", "parola123", "40712345678");
    assert(user.verifyPassword("parola123") == true);
}

void TestUser::all() {
    constructor();
    parametersConstructor();
    lineConstructor();
    copyConstructor();
    getId();
    setId();
    getFirstName();
    setFirstName();
    getLastName();
    setLastName();
    getAge();
    setAge();
    getEmail();
    setEmail();
    getPhoneNumber();
    setPhoneNumber();
    verifyPassword();
}