#include <iostream>
#include <cstring>
using namespace std;

class Text {
    char* data;

public:
    Text(const char* str = "") {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }

    // Copy constructor
    Text(const Text& t) {
        data = new char[strlen(t.data) + 1];
        strcpy(data, t.data);
    }

    // Copy assignment
    Text& operator=(const Text& t) {
        if (this != &t) {
            char* temp = new char[strlen(t.data) + 1];
            strcpy(temp, t.data);

            delete[] data;
            data = temp;
        }
        return *this;
    }

    // Concatenation
    Text operator+(const Text& t) const {
        char* temp = new char[strlen(data) + strlen(t.data) + 1];

        strcpy(temp, data);
        strcat(temp, t.data);

        Text result(temp);
        delete[] temp;

        return result;
    }

    bool operator==(const Text& t) const {
        return strcmp(data, t.data) == 0;
    }

    bool operator!=(const Text& t) const {
        return !(*this == t);
    }

    friend ostream& operator<<(ostream& out, const Text& t) {
        out << t.data;
        return out;
    }

    ~Text() {
        delete[] data;
    }
};

int main() {
    char str1[200], str2[200];

    cout << "Enter first text: ";
    cin.getline(str1, 200);

    cout << "Enter second text: ";
    cin.getline(str2, 200);

    Text a(str1), b(str2);

    Text c = a + Text(" ") + b;

    cout << "Concatenated text: " << c << '\n';

    cout << boolalpha;
    cout << "Equal: " << (a == b) << '\n';
    cout << "Not equal: " << (a != b) << '\n';

    a = a;

    cout << "After self assignment: " << a << '\n';

    return 0;
}