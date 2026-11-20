
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Staff {
protected:
    string name;
    int id;
    double basic;

public:
    Staff(string n, int i, double b)
        : name(n), id(i), basic(b) {}

    virtual double pay() const = 0;

    virtual void display() const {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Salary: " << pay() << endl;
    }

    virtual ~Staff() {}
};

class Professor : public Staff {
    double research;

public:
    Professor(string n, int i, double b, double r)
        : Staff(n, i, b), research(r) {}

    double pay() const override {
        return basic + basic * 0.42 + research;
    }
};

class LabAssistant : public Staff {
public:
    LabAssistant(string n, int i, double b)
        : Staff(n, i, b) {}

    double pay() const override {
        return basic + basic * 0.42;
    }
};

class GuestFaculty : public Staff {
    double hours, rate;

public:
    GuestFaculty(string n, int i, double h, double r)
        : Staff(n, i, 0), hours(h), rate(r) {}

    double pay() const override {
        return hours * rate;
    }
};

int main() {
    Professor p("Ramya", 101, 50000, 8000);
    LabAssistant l("Deepika", 102, 30000);
    GuestFaculty g("Bhavya", 103, 20, 1000);

    cout << "Professor Details" << endl;
    p.display();

    cout << "\nLab Assistant Details" << endl;
    l.display();

    cout << "\nGuest Faculty Details" << endl;
    g.display();

    return 0;
}
