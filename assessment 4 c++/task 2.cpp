
#include <iostream>
using namespace std;

class Person {
public:
    Person() {
        cout << "Person ";
    }
};

class Student : virtual public Person {
public:
    Student() {
        cout << "Student ";
    }
};

class Staff : virtual public Person {
public:
    Staff() {
        cout << "Staff ";
    }
};

class TeachingAssistant : public Student, public Staff {
public:
    TeachingAssistant() {
        cout << "TA ";
    }
};

int main() {
    TeachingAssistant ta;
    cout << endl;

    return 0;
}
