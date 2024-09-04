#pragma once
#include <vector>
#include "Client.h"

using namespace std;
class Employee : public Person
{
    // att
protected:
    double salary;
    // con
public:
    Employee()
    {
        salary = 0.0;
    }
   
    Employee(string name, int id, string password, double salary) :Person(name, id, password)
    {
        setSalary(salary);
    }
    //setter
    void setSalary(double salary)
    {
        while (!Validation::checkSalary(salary)) {
            cin >> salary;
        }
        this->salary = salary;
    }

    // getter
    double getSalary()
    {
        return salary;
    }

    // methods
    void Display()
    {
        Person::Display();
        cout << "Salary -> " << salary << endl;
    } //

    void addClient(Client& client) {
        clientList.push_back(client);

    }

    Client* searchClient(int id) {
        for (itClient = clientList.begin(); itClient != clientList.end(); ++itClient) {
            if (itClient->getId() == id) {
                return &(*itClient);
            }
        }
        return nullptr;
    }

    void listClient() {
        if (clientList.empty()) {
            cout << "No clients available." << endl;
            return;
        }

        for (itClient = clientList.begin(); itClient != clientList.end(); ++itClient) {
            itClient->Display();
            cout << "=============" << endl;
        }
    }

    void editClient(int id, string name, string password, double balance) {
        Client* client = searchClient(id);
        if (client) {
            client->setName(name);
            client->setPassword(password);
            client->setBalance(balance);
            cout << "Client updated successfully." << endl;
        }
        else {
            cout << "Client not found." << endl;
        }
    }

    ~Employee() {

    }
};

static vector<Employee> employeeList;
static vector<Employee>::iterator itEmployee;


