
#include <iostream>
using namespace std;

int main()
{
    int transactions[10];
    int count = 0;

    for (int i = 1; i <= 12; i++)
    {
        if (count == 10)
        {
            for (int j = 0; j < 9; j++)
                transactions[j] = transactions[j + 1];

            count--;
        }

        transactions[count++] = i * 100;
    }

    cout << "Last 10 Transactions:" << endl;

    for (int i = 0; i < count; i++)
        cout << transactions[i] << endl;

    return 0;
}
