
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Account {
public:
    virtual double rate() const {
        return 3.5;
    }

    virtual ~Account() {
        cout << "Account destroyed" << endl;
    }
};

class SeniorAccount : public Account {
public:
    double rate() const override {
        return 4.0;
    }

    ~SeniorAccount() override {
        cout << "Senior Account destroyed" << endl;
    }
};

int main() {
    vector<unique_ptr<Account>> accounts;

    accounts.push_back(make_unique<Account>());
    accounts.push_back(make_unique<SeniorAccount>());

    cout << "Interest Rates:" << endl;

    for (const auto& a : accounts) {
        cout << a->rate() << endl;
    }

    return 0;
}
