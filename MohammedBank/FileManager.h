#pragma once
#include "DataSourceInterface.h"
#include "FilesHelper.h"
using namespace std;

class FileManager : public DataSourceInterface {
public:
    FileManager() {};
    static void addClient(Client* client) {
        FilesHelper::saveClient(client);
    }

    static void addEmployee(Employee* employee) {
        FilesHelper::saveEmployee(employee);
    }

    static void addAdmin(Admin* admin) {
        FilesHelper::saveAdmin(admin);
    }

    static void getAllClients() {
        FilesHelper::getClients();
    }

    static void getAllEmployees() {
        FilesHelper::getEmployees();
    }

    static void getAllAdmins() {
        FilesHelper::getAdmins();
    }

    static void removeAllClients() {
        FilesHelper::clearFile("clientData.txt", "lastClientId.txt");
    }

    static void removeAllEmployees() {
        FilesHelper::clearFile("employeeData.txt", "lastEmployeeId.txt");
    }

    static void removeAllAdmins() {
        FilesHelper::clearFile("adminData.txt", "lastAdminId.txt");
    }

    static void getAllData() {
        getAllClients();
        getAllEmployees();
        getAllAdmins();
    }

    static void updateClients() {
        removeAllClients();
        for (auto Clientit = clientList.begin(); Clientit != clientList.end(); ++Clientit) {
            addClient(*Clientit);
        }
    }

    static void updateEmployees() {
        removeAllEmployees();
        for (Employeeit = employeeList.begin(); Employeeit != employeeList.end(); Employeeit++) addEmployee(*Employeeit);
    }

    static void updateAdmins() {
        removeAllAdmins();
        for (Adminit = adminList.begin(); Adminit != adminList.end(); Adminit++) addAdmin(*Adminit);
    }

};
