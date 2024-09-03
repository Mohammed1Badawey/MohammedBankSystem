#pragma once
#include "ClientManager.h"

using namespace std;


class FilesHelper;
class EmployeeManager {
public:

    static void printEmployeeMenu() {
        cout << "\t\t\t\t\t   :: Employee Menu ::\n";
        cout << "\t\t\t\t\t 1 - Add new client\n";
        cout << "\t\t\t\t\t 2 - List all clients\n";
        cout << "\t\t\t\t\t 3 - Search for client\n";
        cout << "\t\t\t\t\t 4 - Edit client information\n";
        cout << "\t\t\t\t\t 5 - Change password\n";
        cout << "\t\t\t\t\t 6 - Account information\n";
        cout << "\t\t\t\t\t 7 - Exit\n";
    }

    static Employee* login(int id, string password) {
        if (id > 0 && id <= employeeList.size()) {
            Employee* employee = &(employeeList[id - 1]);
            if (employee->getPassword() == password)
            {
                return employee;
            }
            else {
                cout << "Invalid password.\n";
                return nullptr;
            }
        }
        else {
            cout << "Invalid ID.\n";
            return nullptr;
        }
    }

    static bool employeeOptions(Employee* employee) {
        int choice;
        char op;
        do {
            printEmployeeMenu();
            cout << "\nEnter your choice: ";
            cin >> choice;

            switch (choice) {
                //Add new client
            case 1: {
                string name, password;
                double balance;
                int id = FilesHelper::getLast("lastClientId.txt")+1;
                cout << "Enter client name: ";
                cin >> name;
                cout << "Enter client password: ";
                cin >> password;
                cout << "Enter client balance: ";
                cin >> balance;
                Client* client = new Client(name, id, password, balance);
                employee->addClient(*client);
                FilesHelper::saveClient(*client);
                cout << "Client added successfully.\n";
                FileManager::updateClients();
                client->Display();
                delete client;
                break;
            }

                  //List all clients
            case 2: {
                employee->listClient();
                break;
            }
                  //Search all clients
            case 3: {
                int id;
                cout << "Enter client ID to search: ";
                cin >> id;
                Client* client = employee->searchClient(id);
                if (client) {
                    client->Display();
                }
                else {
                    cout << "Client not found.\n";
                }
                break;
            }
                  //Edit client information
            case 4: {
                int id;
                string name, password;
                double balance;
                cout << "Enter client ID to edit: ";
                cin >> id;
                Client* client = employee->searchClient(id);
                cout << "Enter new client name: ";
                cin >> name;
                cout << "Enter new client password: ";
                cin >> password;
                cout << "Enter new balance: ";
                cin >> balance;
                employee->editClient(id, name, password, balance);
                FileManager::updateClients();
                break;
            }
                  //update employee password
            case 5: {
                ClientManager::updatePassword(employee);
                FileManager::updateEmployees();
                break;
            }
                   // Display
            case 6: {
                employee->Display();
                break;
            }
                  // Exiting
            case 7: {
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
                cout << "Exiting system... Goodbye!\n";
                return false;
            }

        } while (op == 'Y');

        return true;
    }
};
