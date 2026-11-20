
#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

class Vehicle {
protected:
    string regNo;
    double dailyRate;
    bool rented = false;

public:
    Vehicle(string r, double rate)
        : regNo(r), dailyRate(rate) {}

    virtual double charge(int days) const = 0;

    bool rent() {
        if (rented)
            return false;

        rented = true;
        return true;
    }

    double returnVehicle(int lateDays) {
        if (!rented)
            return 0;

        rented = false;

        if (lateDays > 0)
            return lateDays * dailyRate * 1.25;

        return 0;
    }

    virtual void display() const {
        cout << "Registration: " << regNo << endl;
        cout << "Daily Rate: " << dailyRate << endl;
    }

    virtual ~Vehicle() {}
};

class Bicycle : public Vehicle {
public:
    Bicycle(string r, double rate)
        : Vehicle(r, rate) {}

    double charge(int days) const override {
        return dailyRate * days;
    }
};

class MotorVehicle : public Vehicle {
protected:
    double fuelLevel;
    string serviceDueDate;

public:
    MotorVehicle(string r, double rate,
                 double fuel, string date)
        : Vehicle(r, rate),
          fuelLevel(fuel),
          serviceDueDate(date) {}
};

class TwoWheeler : public MotorVehicle {
public:
    TwoWheeler(string r, double rate,
               double fuel, string date)
        : MotorVehicle(r, rate, fuel, date) {}

    double charge(int days) const override {
        return dailyRate * days + 50;
    }
};

class Car : public MotorVehicle {
protected:
    int seats;

public:
    Car(string r, double rate, double fuel,
        string date, int s)
        : MotorVehicle(r, rate, fuel, date),
          seats(s) {}

    double charge(int days) const override {
        return dailyRate * days;
    }
};

class ElectricCar : public Car {
    double batteryCapacity;
    double pricePerKWh;

public:
    ElectricCar(string r, double rate,
                double battery, double price, int s)
        : Car(r, rate, 100, "N/A", s),
          batteryCapacity(battery),
          pricePerKWh(price) {}

    double charge(int days) const override {
        return dailyRate * days
             + batteryCapacity * pricePerKWh * 0.10;
    }
};

// New vehicle type
class ElectricBus : public Vehicle {
    double batteryCapacity;
    double pricePerKWh;

public:
    ElectricBus(string r, double rate,
                double battery, double price)
        : Vehicle(r, rate),
          batteryCapacity(battery),
          pricePerKWh(price) {}

    double charge(int days) const override {
        return dailyRate * days
             + batteryCapacity * pricePerKWh * 0.15;
    }
};

int main() {
    vector<unique_ptr<Vehicle>> fleet;

    fleet.push_back(
        make_unique<Bicycle>("BI-101", 100));

    fleet.push_back(
        make_unique<TwoWheeler>(
            "TW-202", 250, 5, "2027-03-01"));

    fleet.push_back(
        make_unique<Car>(
            "CA-303", 1200, 20, "2027-04-01", 5));

    fleet.push_back(
        make_unique<ElectricCar>(
            "EV-404", 1500, 60, 8, 5));

    fleet.push_back(
        make_unique<ElectricBus>(
            "EB-505", 2000, 200, 8));

    cout << "VEHICLE RENTAL DETAILS" << endl;

    for (const auto& v : fleet) {
        v->display();

        cout << "Rental Charge: "
             << v->charge(2) << endl;

        if (v->rent()) {
            cout << "Status: Rented" << endl;
        }

        cout << "Late Return Charge: "
             << v->returnVehicle(2) << endl;

        cout << "-------------------" << endl;
    }

    return 0;
}
