#include <iostream>
#include <string>
using namespace std;

struct Employee {
    string name;
    Employee* next;
};

class EmployeeList {
    Employee* tail;
public:
    EmployeeList() { tail = nullptr; }
    void addEmployee(string name) {
        Employee* newEmp = new Employee();
        newEmp->name = name;
        if (!tail) {
            tail = newEmp;
            tail->next = tail;
        } else {
            newEmp->next = tail->next;
            tail->next = newEmp;
            tail = newEmp;
        }
        cout << name << " added successfully.\n";
    }
    void deleteEmployee(string name) {
        if (!tail) { cout << "List empty.\n"; return; }
        Employee* current = tail->next;
        Employee* prev = tail;
        do {
            if (current->name == name) {
                if (current == tail && current->next == tail) {
                    delete current;
                    tail = nullptr;
                } else {
                    prev->next = current->next;
                    if (current == tail) tail = prev;
                    delete current;
                }
                cout << name << " deleted successfully.\n";
                return;
            }
            prev = current;
            current = current->next;
        } while (current != tail->next);
        cout << name << " not found.\n";
    }
    void findEmployee(string name) {
        if (!tail) { cout << "List empty.\n"; return; }
        Employee* temp = tail->next;
        do {
            if (temp->name == name) {
                cout << name << " found successfully.\n";
                return;
            }
            temp = temp->next;
        } while (temp != tail->next);
        cout << name << " not found.\n";
    }
    void display() {
        if (!tail) { cout << "No employees.\n"; return; }
        Employee* temp = tail->next;
        do {
            cout << temp->name << " -> ";
            temp = temp->next;
        } while (temp != tail->next);
        cout << "(head)\n";
    }
};

int main() {
    EmployeeList list;
    list.addEmployee("Ali");
    list.addEmployee("Sara");
    list.addEmployee("Ahmed");
    list.display();
    list.findEmployee("Sara");
    list.deleteEmployee("Ahmed");
    list.display();
    list.deleteEmployee("Zara");
    return 0;
}
