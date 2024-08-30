#pragma once
#include <vector>
class Admin;
class Employee;
class Client;

extern std::vector<Client*> clientList;
extern std::vector<Employee*> employeeList;
extern std::vector<Admin*> adminList;

static std::vector<Client*>::iterator Clientit;
static std::vector<Employee*>::iterator Employeeit;
static std::vector<Admin*>::iterator Adminit;

class GlobalVectors
{};

