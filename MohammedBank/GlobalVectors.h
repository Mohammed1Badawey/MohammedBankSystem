#pragma once
#include <vector>
using namespace std;
class Admin;
class Employee;
class Client;

extern vector<Client*> clientList;
extern vector<Employee*> employeeList;
extern vector<Admin*> adminList;

static vector<Client*>::iterator Clientit;
static vector<Employee*>::iterator Employeeit;
static vector<Admin*>::iterator Adminit;

class GlobalVectors
{};

