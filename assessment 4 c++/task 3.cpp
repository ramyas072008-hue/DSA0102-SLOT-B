
#include <iostream>
using namespace std;

class Engine {
public:
    Engine() {
        cout << "Engine ";
    }

    ~Engine() {
        cout << "~Engine ";
    }
};

class Vehicle {
public:
    Vehicle() {
        cout << "Vehicle ";
    }

    ~Vehicle() {
        cout << "~Vehicle ";
    }
};

class Car : public Vehicle {
    Engine e;

public:
    Car() {
        cout << "Car ";
    }

    ~Car() {
        cout << "~Car ";
    }
};

int main() {
    {
        Car c;
        cout << "| ";
    }

    cout << endl;
    return 0;
}
