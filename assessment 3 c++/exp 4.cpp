#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

class Money {
    long long paise;

public:
    Money(long long r = 0, int p = 0)
        : paise(r * 100 + p) {}

    Money operator+(const Money& m) const {
        Money temp;
        temp.paise = paise + m.paise;
        return temp;
    }

    Money operator-(const Money& m) const {
        Money temp;
        temp.paise = paise - m.paise;
        return temp;
    }

    Money& operator+=(const Money& m) {
        paise += m.paise;
        return *this;
    }

    bool operator==(const Money& m) const {
        return paise == m.paise;
    }

    bool operator<(const Money& m) const {
        return paise < m.paise;
    }

    friend ostream& operator<<(ostream& out, const Money& m) {
        long long value = m.paise;
        if (value < 0)
            out << "-Rs ";
        else
            out << "Rs ";

        value = llabs(value);

        out << value / 100 << "."
            << setw(2) << setfill('0') << value % 100
            << setfill(' ');
        return out;
    }

    friend istream& operator>>(istream& in, Money& m) {
        long long r;
        int p;
        in >> r >> p;
        m.paise = r * 100 + p;
        return in;
    }
};

int main() {
    Money a, b;

    cout << "Enter first amount (rupees paise): ";
    cin >> a;

    cout << "Enter second amount (rupees paise): ";
    cin >> b;

    Money c = a + b;

    cout << "Addition: " << c << '\n';
    cout << "Subtraction: " << a - b << '\n';

    a += b;
    cout << "After += : " << a << '\n';

    cout << boolalpha;
    cout << "Equal: " << (a == c) << '\n';
    cout << "Less than: " << (c < b) << '\n';

    Money x(0, 75), y(0, 50);
    cout << "Paise carry test: " << x + y << '\n';

    return 0;
}