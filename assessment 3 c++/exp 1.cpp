#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Book {
    string title, author;
    int copies;

public:
    Book() : Book("", "", 0) {}

    explicit Book(string t) : Book(t, "", 0) {}

    Book(string t, string a, int c)
        : title(t), author(a), copies(c) {
        if (c < 0)
            throw invalid_argument("Copies cannot be negative");
    }

    void display() const {
        cout << "Title: " << title
             << "\nAuthor: " << author
             << "\nCopies: " << copies << "\n\n";
    }
};

int main() {
    try {
        Book b1;
        Book b2("The Alchemist");
        Book b3("Wings of Fire", "A. P. J. Abdul Kalam", 5);

        cout << "Default Book:\n";
        b1.display();

        cout << "Donated Book:\n";
        b2.display();

        cout << "Complete Book:\n";
        b3.display();

        Book b4("Invalid Book", "Unknown", -2);
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << '\n';
    }

    return 0;
}