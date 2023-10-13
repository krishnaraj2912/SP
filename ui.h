#include <iostream>
#include <string>
#include <fstream>
#include "student.h"
#include "professor.h"
#include "messworker.h"
//#include "messsupervisor.h"
#pragma once

struct User {
    int loginid;
    std::string password;
};

class UserInterface {
public:
    void menu() {}
};

User createUserAccount() {
    User user;
    std::cout << "\n Enter your id (no) you would like to have: ";
    std::cin >> user.loginid;

    do {
        std::cout << "\n Enter the password: ";
        std::cin >> user.password;
        std::string confirmPassword;
        std::cout << "\n Enter the password again for confirmation: ";
        std::cin >> confirmPassword;

        if (user.password == confirmPassword) {
            return user;
        }
    } while (true);
}

User login(std::ifstream& file, int loginid, const std::string& password) {
    User user;
    while (file.read(reinterpret_cast<char*>(&user), sizeof(user))) {
        if (user.loginid == loginid && user.password == password) {
            return user;
        }
    }
    throw std::runtime_error("Invalid credentials");
}

std::string getUserTypeFileName(int userType) {
    if (userType == 1) {
        return "student.dat";
    } else if (userType == 2) {
        return "professor.dat";
    } else if (userType == 3) {
        return "messworker.dat";
    }
    throw std::runtime_error("Invalid user type");
}

int main() {
    std::cout << "\n LOGIN SYSTEM 1.STUDENT 2.PROFESSOR 3.MESS WORKER ";
    std::cout << "\n Enter your choice: ";
    int userType;
    std::cin >> userType;

    User user;
    UserInterface userInterface;

    if (userType >= 1 && userType <= 3) {
        std::cout << "\n Menu 1.New id 2.Login old id ";
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            user = createUserAccount();
            std::ofstream file;
            file.open(getUserTypeFileName(userType), std::ios::out | std::ios::binary | std::ios::app);
            file.write(reinterpret_cast<char*>(&user), sizeof(user));
        } else if (choice == 2) {
            std::cout << "\n Enter your login id: ";
            int loginid;
            std::cin >> loginid;
            std::cout << "\n Enter your password: ";
            std::string password;
            std::cin >> password;
            std::ifstream file;
            file.open(getUserTypeFileName(userType), std::ios::in | std::ios::binary);
            user = login(file, loginid, password);
            userInterface.menu();
        }
    } else {
        std::cout << "\n Invalid user type choice";
    }

    return 0;
}
