#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdexcept>
using namespace std;

class Complex {
    double real, imag;

public:
    Complex() : real(0), imag(0) {}

    Complex(double r) : real(r), imag(0) {}

    Complex(double r, double i) : real(r), imag(i) {}

    Complex operator+(const Complex& c) const {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator-(const Complex& c) const {
        return Complex(real - c.real, imag - c.imag);
    }

    Complex operator*(const Complex& c) const {
        return Complex(
            real * c.real - imag * c.imag,
            real * c.imag + imag * c.real
        );
    }

    Complex operator/(const Complex& c) const {
        double denominator =
            c.real * c.real + c.imag * c.imag;

        if (denominator < 1e-12)
            throw domain_error("Division by zero impedance");

        return Complex(
            (real * c.real + imag * c.imag) / denominator,
            (imag * c.real - real * c.imag) / denominator
        );
    }

    bool operator==(const Complex& c) const {
        return fabs(real - c.real) < 1e-9 &&
               fabs(imag - c.imag) < 1e-9;
    }

    double magnitude() const {
        return sqrt(real * real + imag * imag);
    }

    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << fixed << setprecision(2)
            << c.real;

        if (c.imag >= 0)
            out << " + " << c.imag << "j";
        else
            out << " - " << fabs(c.imag) << "j";

        return out;
    }
};

Complex calculateRLC(double R, double L, double C, double omega) {
    if (omega <= 0 || C <= 0)
        throw invalid_argument("Omega and capacitance must be positive");

    double imaginary = omega * L - 1.0 / (omega * C);

    return Complex(R, imaginary);
}

int main() {
    double R1, L1, C1;
    double R2, L2, C2;
    double omega;

    cout << "Enter R1 L1 C1: ";
    cin >> R1 >> L1 >> C1;

    cout << "Enter R2 L2 C2: ";
    cin >> R2 >> L2 >> C2;

    cout << "Enter angular frequency: ";
    cin >> omega;

    try {
        Complex z1 = calculateRLC(R1, L1, C1, omega);
        Complex z2 = calculateRLC(R2, L2, C2, omega);

        Complex series = z1 + z2;
        Complex parallel = (z1 * z2) / (z1 + z2);

        cout << "Z1: " << z1 << '\n';
        cout << "Z2: " << z2 << '\n';

        cout << "Series impedance: " << series << '\n';
        cout << "Series magnitude: "
             << series.magnitude() << '\n';

        cout << "Parallel impedance: " << parallel << '\n';
        cout << "Parallel magnitude: "
             << parallel.magnitude() << '\n';
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << '\n';
    }

    return 0;
}