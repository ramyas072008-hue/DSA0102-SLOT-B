
#include <iostream>
using namespace std;

struct Parcel
{
    double weight;
    bool express;
    bool insured;
};

void charge(int grams)
{
    cout << "Weight in grams: " << grams << endl;
}

void charge(double kg, bool express = false,
             bool insured = false)
{
    double cost = kg * 50;

    if (express)
        cost += 30;

    if (insured)
        cost += 20;

    cout << "Courier charge: " << cost << endl;
}

void charge(Parcel p)
{
    double cost = p.weight * 50;

    if (p.express)
        cost += 30;

    if (p.insured)
        cost += 20;

    cout << "Parcel charge: " << cost << endl;
}

int main()
{
    charge(500);
    charge(2);
    charge(2.0);
    charge(2.0f);
    charge(3.0, true);
    charge(Parcel{4.0, true, true});

    return 0;
}
