#pragma once
#include "Parser.h"
#include "GlobalVectors.h"
#include <thread>


using namespace std;

class FilesHelper {
public:


    static void saveLast(const string& fileName, int id) {
        ofstream ofs(fileName);
        if (ofs.is_open()) {
            ofs << id << endl;
            ofs.close();
        }
        else {
            cout << "Error opening " << fileName << " for writing!" << endl;
        }
    }

    static int getLast(const string& fileName) {
        ifstream ifs(fileName);

        if (ifs.is_open()) {
            int id;
            ifs >> id;
            ifs.close();
            return id;
        }

        else {
            cout << "Error opening " << fileName << " for reading!" << endl;
            return -1;
        }
    }

    static void saveClient(Client* c) {
        ofstream ofs("clientData.txt", ios::app);
        if (ofs.is_open()) {
            ofs << c->getId() << "|" << c->getName() << "|" << c->getPassword() << "|" << c->getBalance() << endl;
            int i = c->getId();
            saveLast("lastClientId.txt", i);
        }
        else {
            cout << "Error opening clientData.txt for writing!" << endl;
        }
    }

    static void saveEmployee(Employee* e) {
        ofstream ofs ("employeeData.txt", ios::app);
        if (ofs.is_open()) {
            ofs << e->getId() << "|" << e->getName() << "|" << e->getPassword() << "|" << e->getSalary() << endl;
            int i = e->getId();
            saveLast("lastEmployeeId.txt", i);
        }
        else {
            cout << "Error opening employeeData.txt for writing!" << endl;
        }
    }

    static void saveAdmin(Admin* a) {
        ofstream ofs ("adminData.txt", ios::app);
        if (ofs.is_open()) {
            ofs << a->getId() << "|" << a->getName() << "|" << a->getPassword() << "|" << a->getSalary() << endl;
            int i = a->getId();
            saveLast("lastAdminId.txt", i);
        }
        else {
            cout << "Error opening adminData.txt for writing!" << endl;
        }
    }

    static void getClients() {
        ifstream ifs("clientData.txt");
        if (ifs.is_open()) {
            string line;
            while (getline(ifs, line)) {
                Client* c = new Client(Parser::parseToClient(line));
                clientList.push_back(c);
            }
        }
        else {
            cout << "Error opening clientData.txt for reading!" << endl;
        }
    }

    static void getEmployees() {
        ifstream ifs("employeeData.txt");
        if (ifs.is_open()) {
            string line;
            while (getline(ifs, line)) {
                Employee* e = new Employee(Parser::parseToEmployee(line));
                employeeList.push_back(e);
            }
        }
        else {
            cout << "Error opening employeeData.txt for reading!" << endl;
        }
    }

    static void getAdmins() {
        ifstream ifs("adminData.txt");
        if (ifs.is_open()) {
            string line;
            while (getline(ifs, line)) {
                Admin* admin = Admin::getInstance();
                Admin tempAdmin = *Parser::parseToAdmin(line);
                admin->setId(tempAdmin.getId());
                admin->setName(tempAdmin.getName());
                admin->setPassword(tempAdmin.getPassword());
                admin->setSalary(tempAdmin.getSalary());
                adminList.push_back(admin);
            }
        }
        else {
            cout << "Error opening adminData.txt for reading!" << endl;
        }
    }

    static void getAllData() {
        thread clientThread(getClients);
        thread employeeThread(getEmployees);
        thread adminThread(getAdmins);

        
        clientThread.join();
        employeeThread.join();
        adminThread.join();
    }

    static void clearFile(const string& fileName, const string& lastIdFile) {
        ofstream ofs(fileName, ios::trunc);
        if (ofs.is_open()) {
            saveLast(lastIdFile, 0);
        }
        else {
            cout << "Error opening " << fileName << " for clearing!" << endl;
        }

    }
};
