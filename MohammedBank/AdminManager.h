#pragma once
#include "Admin.h"
#include "EmployeeManager.h"



using namespace std;

class AdminManager {
public:

    static void printAdminMenu() {
        cout << "\t\t\t\t\t   :: Admin Menu ::\n";
        cout << "\t\t\t\t\t 1 - Add Client\n";
        cout << "\t\t\t\t\t 2 - Add Employee\n";
        cout << "\t\t\t\t\t 3 - Employee Menu\n";
        cout << "\t\t\t\t\t 4 - Edit Client Information\n";
        cout << "\t\t\t\t\t 5 - Edit Employee Information\n";
        cout << "\t\t\t\t\t 6 - List all Clients\n";
        cout << "\t\t\t\t\t 7 - List all Employees\n";
        cout << "\t\t\t\t\t 8 - Account information\n";
        cout << "\t\t\t\t\t 9 - Update salary\n";
        cout << "\t\t\t\t\t 10 - Exit\n";
    }

    static void printEmployeeMenu() {
        EmployeeManager::employeeOptions(nullptr);
    }

    static Admin* login(int id, string password) {
        Admin* admin = Admin::getInstance();


        if (id != admin->getId())
        {
            cout << "Invalid ID.\n";
            return nullptr;
        }

        if (admin->getPassword() != password) {
            cout << "Invalid password.\n";
            return nullptr;
        }

        return admin;
    }


    static bool adminOptions() {
        int choice;
        char op;
        Admin* admin = Admin::getInstance();

        do {
            printAdminMenu();
            cout << "\nEnter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1: {
                // Add Client
                string name, password;
                double balance;
                int id = FilesHelper::getLast("lastClientId.txt") + 1;
                cout << "Enter client name: ";
                cin >> name;
                cout << "Enter client password: ";
                cin >> password;
                cout << "Enter client balance: ";
                cin >> balance;
                Client* client = new Client(name, id, password, balance);
                admin->addClient(*client);
                FilesHelper::saveClient(client);
                cout << "Client added successfully.\n";
                FileManager::updateClients();
                client->Display();
                delete client;
                break;
            }

            case 2: {
                // Add Employee
                string name, password;
                double salary;
                int id = FilesHelper::getLast("lastEmployeeId.txt") + 1;
                cout << "Enter employee name: ";
                cin >> name;
                cout << "\nEnter employee password: ";
                cin >> password;
                cout << "\nEnter employee salary: ";
                cin >> salary;
                Employee* employee = new Employee(name, id, password, salary);
                admin->addEmployee(*employee);
                FilesHelper::saveEmployee(employee);
                cout << "\nEmployee added successfully.\n";
                FileManager::updateClients();
                employee->Display();
                delete employee;
                break;
            }

            case 3: {
                printEmployeeMenu();
                break;
            }

            case 4: {
                // Edit Client Information
                int id;
                string name, password;
                double balance;
                cout << "Enter client ID to edit: ";
                cin >> id;
                Client* client = admin->searchClient(id);
                cout << "Enter new client name: ";
                cin >> name;
                cout << "Enter new client password: ";
                cin >> password;
                cout << "Enter new balance: ";
                cin >> balance;
                admin->editClient(id, name, password, balance);
                FileManager::updateClients();
                break;
            }

            case 5: {
                // Edit Employee Information
                int id;
                string name, password;
                double salary;
                cout << "Enter employee ID to edit: ";
                cin >> id;
                Employee* employee = admin->searchEmployee(id);
                cout << "Enter new employee name: ";
                cin >> name;
                cout << "Enter new employee password: ";
                cin >> password;
                cout << "Enter new employee salary: ";
                cin >> salary;
                admin->editEmployee(id, name, password, salary);
                FileManager::updateEmployees();
                break;
            }

            case 6: {
                // List all Clients
                admin->listClient();
                break;
            }

            case 7: {
                // List all Employees
                admin->listEmployee();
                break;
            }

            case 8: {
                admin->Display();
                break;
            }

            case 9: {
                int id;
                cout << "Enter employee ID ";
                cin >> id;
                Employee* employee = admin->searchEmployee(id);
                cout << employee->getName() << " salary : " << employee->getSalary() << endl;
                updateSalary(employee);
                cout << "Salary after is -> "  << employee->getSalary() << endl;
                FileManager::updateEmployees();
                break;
            }

            case 10: {
                cout << "Exiting system... Goodbye!\n";
                return false;
            }

            default:
                cout << "Invalid choice, please try again.\n";
            }

            do {
                cout << "Press [Y] to Continue or [N] to Exit: ";
                cin >> op;
                op = toupper(op);
                if (op != 'Y' && op != 'N') {
                    cout << "Invalid input. Please enter 'Y' or 'N'.\n";
                }
            } while (op != 'Y' && op != 'N');

            if (op == 'N') {
                system("cls");
                cout << "Exiting system... Goodbye!\n";
                return false;
            }

        } while (op == 'Y');

        return true;
    }

    static void updateSalary(Employee* employee) {
        double oldSalary, newSalary,Percentage;
        oldSalary = employee->getSalary();
        cout << "Enter Percentage: ";
        cin >> Percentage;

        newSalary = (oldSalary * Percentage / 100) + oldSalary;
        

        employee->setSalary(newSalary);
        cout << "Salary updated successfully.\n";
    }
};
