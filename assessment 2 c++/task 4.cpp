
#include <iostream>
using namespace std;

class SavingsAccount
{
private:
    int accountNumber;
    double balance;
    double transactions[10];
    int count;

public:
    SavingsAccount(int acc, double bal)
    {
        accountNumber = acc;
        balance = bal;
        count = 0;
    }

    void deposit(double amount)
    {
        balance += amount;

        if (count == 10)
        {
            for (int i = 0; i < 9; i++)
                transactions[i] = transactions[i + 1];

            count--;
        }

        transactions[count++] = amount;
    }

    void withdraw(double amount)
    {
        if (amount > balance)
        {
            cout << "Insufficient balance" << endl;
            return;
        }

        balance -= amount;

        if (count == 10)
        {
            for (int i = 0; i < 9; i++)
                transactions[i] = transactions[i + 1];

            count--;
        }

        transactions[count++] = -amount;
    }

    void miniStatement();
};

void SavingsAccount::miniStatement()
{
    cout << "Account Number: " << accountNumber << endl;
    cout << "Balance: " << balance << endl;
    cout << "Mini Statement:" << endl;

    for (int i = 0; i < count; i++)
        cout << transactions[i] << endl;
}

int main()
{
    SavingsAccount s(1001, 5000);

    s.deposit(1000);
    s.withdraw(500);
    s.deposit(2000);

    s.miniStatement();

    return 0;
}
