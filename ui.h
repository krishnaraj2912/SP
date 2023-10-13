#include <iostream>
#include <fstream>
#include <string>
#include "student.h"
#include "professor.h"
#include "messworker.h"
#pragma once

class UI {
    int loginid;
    std::string password;
    std::string cpassword;

public:
    Student p1;
    Professor p2;
    MessWorker p3;

    void display();
    void studentMenu();
    void professorMenu();
    void messWorkerMenu();
    void registerAndLogin(const std::string& userType, const std::string& dataFile, void (UI::*inputFunc)());
};

void UI::display() {
    std::cout << "\n LOGIN SYSTEM 1. STUDENT 2. PROFESSOR 3. MESS WORKER ";
    std::cout << "\n Enter your choice : ";
    int ch;
    std::cin >> ch;

    switch (ch) {
        case 1: {
            studentMenu();
            break;
        }
        case 2: {
            professorMenu();
            break;
        }
        case 3: {
            messWorkerMenu();
            break;
        }
        default: {
            std::cout << "\n Invalid choice.";
            break;
        }
    }
}

void UI::registerAndLogin(const std::string& userType, const std::string& dataFile, void (UI::*inputFunc)()) {
    std::cout << "\n Menu 1. New id 2. Login old id ";
    int ch1;
    std::cin >> ch1;

    if (ch1 == 1) {
        // New ID
        std::cout << "\n Enter your id (no) you would like to have : ";
        std::cin >> loginid;

        do {
            std::cout << "\n Enter the password: ";
            std::cin.ignore();
            std::getline(std::cin, password);
            std::cout << "\n Enter the password again for confirmation : ";
            std::getline(std::cin, cpassword);

            if (password == cpassword) {
                break;
            }
        } while (true);

        (this->*inputFunc)();

        std::ofstream fout(dataFile, std::ios::out | std::ios::binary | std::ios::app);
        fout.write(reinterpret_cast<std::byte*>(this), sizeof(UI));
        fout.close();
    } else if (ch1 == 2) {
        // Login with existing ID
        std::cout << "\n Enter your login id : ";
        int lg;
        std::string ps;
        std::cin >> lg;
        std::cin.ignore();
        std::cout << "\n Enter your password : ";
        std::getline(std::cin, ps);

        UI A;
        int f = 0;
        std::ifstream fin(dataFile, std::ios::in | std::ios::binary);

        while (fin.read(reinterpret_cast<std::byte*>(&A), sizeof(A))) {
            if (A.loginid == lg && A.password == ps) {
                std::cout << "\n Welcome back\n";
                f = 1;
                break;
            }
        }

        if (f == 0) {
            std::cout << "\n Wrong credentials";
        } else {
            (A.*inputFunc)();
        }
    } else {
        std::cout << "\n Invalid choice.";
    }
}

void UI::studentMenu() {
    registerAndLogin("student", "student.dat", &UI::p1.student_input);
}

void UI::professorMenu() {
    registerAndLogin("professor", "professor.dat", &UI::p2.professor_input);
}

void UI::messWorkerMenu() {
    registerAndLogin("mess worker", "messworker.dat", &UI::p3.messworker_input);
}

int main() {
    UI userInterface;
    userInterface.display();

    return 0;
}
