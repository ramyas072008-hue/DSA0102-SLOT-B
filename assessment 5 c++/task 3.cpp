
#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;

class Bill {
public:
    virtual double total() const = 0;
    virtual ~Bill() = default;
};

class OPBill : public Bill {
    double consultation, tests;

public:
    OPBill(double c, double t)
        : consultation(c), tests(t) {}

    double total() const override {
        return consultation + tests;
    }
};

class IPBill : public Bill {
    int days;
    double rate, surgery;

public:
    IPBill(int d, double r, double s)
        : days(d), rate(r), surgery(s) {}

    double total() const override {
        return days * rate + surgery;
    }
};

struct SimpleBill {
    int type;
    int days;
    double a, b;
};

double switchTotal(const SimpleBill& bill) {
    switch (bill.type) {
        case 1:
            return bill.a + bill.b;

        case 2:
            return bill.days * bill.a + bill.b;

        default:
            return 0;
    }
}

int main() {

    vector<Bill*> bills;

    bills.push_back(new OPBill(500, 1200));
    bills.push_back(new IPBill(2, 2000, 10000));
    bills.push_back(new OPBill(700, 800));
    bills.push_back(new IPBill(4, 1500, 5000));

    double virtualSum = 0;

    for (Bill* b : bills) {
        virtualSum += b->total();
    }

    vector<SimpleBill> data = {
        {1, 0, 500, 1200},
        {2, 2, 2000, 10000},
        {1, 0, 700, 800},
        {2, 4, 1500, 5000}
    };

    double switchSum = 0;

    for (const auto& b : data) {
        switchSum += switchTotal(b);
    }

    cout << "Virtual Total: " << virtualSum << endl;
    cout << "Switch Total: " << switchSum << endl;

    if (virtualSum == switchSum)
        cout << "Both results are equal" << endl;
    else
        cout << "Results are different" << endl;

    for (Bill* b : bills) {
        delete b;
    }

    return 0;
}
