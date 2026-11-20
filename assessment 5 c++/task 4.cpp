
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Bill {
protected:
    string patient;

public:
    Bill(string p) : patient(p) {}

    virtual double total() const = 0;

    virtual string type() const = 0;

    virtual ~Bill() = default;
};

class OPBill : public Bill {
    double consultation, tests;

public:
    OPBill(string p, double c, double t)
        : Bill(p), consultation(c), tests(t) {}

    double total() const override {
        return consultation + tests;
    }

    string type() const override {
        return "OutPatient";
    }
};

class TelemedicineBill : public Bill {
    double consultationFee, monitoringFee;

public:
    TelemedicineBill(string p, double c, double m)
        : Bill(p), consultationFee(c), monitoringFee(m) {}

    double total() const override {
        return consultationFee + monitoringFee;
    }

    string type() const override {
        return "Telemedicine";
    }
};

class Payer {
public:
    virtual double amountCovered(const Bill& b) const = 0;

    virtual ~Payer() = default;
};

class CorporateTieUp : public Payer {
    double limit;

public:
    CorporateTieUp(double l) : limit(l) {}

    double amountCovered(const Bill& b) const override {
        return 0.80 * min(b.total(), limit);
    }
};

int main() {

    OPBill op("Ravi", 500, 1200);

    TelemedicineBill tm("Meena", 1000, 500);

    CorporateTieUp corporate(2000);

    cout << op.type() << " Bill: "
         << op.total() << endl;

    cout << tm.type() << " Bill: "
         << tm.total() << endl;

    cout << "Corporate Covered Amount: "
         << corporate.amountCovered(tm) << endl;

    return 0;
}
