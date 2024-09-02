#pragma once
#include "AdminManager.h"
#include "FileManager.h"
#include <windows.h>
#include <chrono>
#include <thread>

using namespace std;

class Screens {
public:

    static void bankName() {
        system("Color 3F");
        printTextGradually("\t\t\t\t\t******************************************", 7); //7
        printTextGradually("\t\t\t\t\t*           * * * * * * * * * *          *", 7);
        printTextGradually("\t\t\t\t\t*           *  Mohammed Bank  *          *", 7);
        printTextGradually("\t\t\t\t\t*           * * * * * * * * * *          *", 7);
        printTextGradually("\t\t\t\t\t******************************************", 7);
        this_thread::sleep_for(chrono::milliseconds(1500)); // تأخير بعد عرض النص
    }


    static void welcome() {
        system("Color 3F");
        setCursorPosition(49, 0);
        printTextGradually("Welcome to Mohammed Bank!", 35); //35
        this_thread::sleep_for(chrono::milliseconds(300)); // 500
        system("cls");
    }


    static void loginOptions() {
        cout << "\t\t\t\t\t   Select login option:\n";
        cout << "\t\t\t\t\t   1. Client\n";
        cout << "\t\t\t\t\t   2. Employee\n";
        cout << "\t\t\t\t\t   3. Admin\n";
        cout << "\t\t\t\t\t   4. Exit\n";
    }

    static int loginAs() {
        int option;
        loginOptions();
        cout << "\t\t\t\t\tEnter your choice: ";
        while (!(cin >> option) || option < 1 || option > 4) {
            cout << "Invalid choice. Please enter a number between 1 and 4: ";
            cin >> option;
            cout << endl;
        }
        return option;
    }

    static void invalid(int c) {
        system("Color 4F");
        cout << "Invalid choice (" << c << "). Please try again.\n";
        Sleep(2000);
        system("Color 0F");
    }

    static void logout() {
        cout << "Logging out... Goodbye!\n";
        Sleep(1000);
        system("cls");
        return;
    }

    static void loginScreen(int c) {
        int choice = c;

        switch (choice) {

        case 1: {
            int id;
            string password;
            cout << "\t\t\t\t\tEnter your id: ";
            cin >> id;
            cout << "\t\t\t\t\tEnter your password: ";
            cin >> password;
            Client* client = ClientManager::login(id, password);
            system("cls");

            if (client != nullptr) {
                while (ClientManager::clientOptions(client) != false);
                logout();
            }
            else {
                invalid(c);
            }
            break;
        }

        case 2: {
            int id;
            string password;
            cout << "\t\t\t\t\tEnter your id: ";
            cin >> id;
            cout << "\t\t\t\t\tEnter your password: ";
            cin >> password;

            Employee* employee = EmployeeManager::login(id, password);
            system("cls");

            if (employee != nullptr) {
                while (EmployeeManager::employeeOptions(employee) != false);
                logout();
            }
            else {
                invalid(c);
            }
            break;
        }

        case 3: {
            int id;
            string password;
            cout << "\t\t\t\t\tEnter your id: ";
            cin >> id;
            cout << "\t\t\t\t\tEnter your password: ";
            cin >> password;
            system("cls");

            Admin* admin = AdminManager::login(id, password);
            if (admin != nullptr) {
                AdminManager::adminOptions();
            }
            else {
                invalid(c);
            }
            break;
        }

        case 4: {
            logout();
            break;
        }

        default: {
            invalid(c);
            break;
        }

        }
    }

    static void runApp() {
        FileManager::getAllData();
        bankName();
        welcome();
        Sleep(1000);
        loginScreen(loginAs());
        system("Color 0F");
    }

private:
    static void setCursorPosition(int x, int y) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD pos = { x, y };
        SetConsoleCursorPosition(hConsole, pos);
    }

    static void printTextGradually(const string& text, int delay_ms) {
        for (char ch : text) {
            cout << ch;
            cout.flush();  // لضمان طباعة الحرف فوراً
            this_thread::sleep_for(chrono::milliseconds(delay_ms));
        }
        cout << endl;  // لطباعة سطر جديد بعد الانتهاء من النص
    }
};