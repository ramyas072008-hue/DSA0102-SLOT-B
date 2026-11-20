#include <iostream>
using namespace std;

class Event {
    int rows, seats;
    char** seatMap;
    int booked;

public:
    Event(int r, int s)
        : rows(r), seats(s), seatMap(nullptr), booked(0) {

        if (rows > 0 && seats > 0) {
            seatMap = new char*[rows];

            for (int i = 0; i < rows; i++) {
                seatMap[i] = new char[seats];

                for (int j = 0; j < seats; j++)
                    seatMap[i][j] = 'O';
            }
        }

        cout << "Event created\n";
    }

    void book(int r, int s) {
        if (r >= 0 && r < rows &&
            s >= 0 && s < seats &&
            seatMap[r][s] == 'O') {

            seatMap[r][s] = 'X';
            booked++;
            cout << "Seat booked\n";
        } else {
            cout << "Booking failed\n";
        }
    }

    void cancel(int r, int s) {
        if (r >= 0 && r < rows &&
            s >= 0 && s < seats &&
            seatMap[r][s] == 'X') {

            seatMap[r][s] = 'O';
            booked--;
            cout << "Booking cancelled\n";
        } else {
            cout << "Cancellation failed\n";
        }
    }

    void display() const {
        cout << "Seat Map:\n";

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < seats; j++)
                cout << seatMap[i][j] << " ";
            cout << '\n';
        }
    }

    ~Event() {
        for (int i = 0; i < rows; i++)
            delete[] seatMap[i];

        delete[] seatMap;

        cout << "Event closed. Booked seats: "
             << booked << '\n';
    }
};

int main() {
    int r, s, row, seat;

    cout << "Enter rows and seats: ";
    cin >> r >> s;

    Event e(r, s);

    cout << "Enter row and seat to book: ";
    cin >> row >> seat;
    e.book(row, seat);

    cout << "Enter row and seat to cancel: ";
    cin >> row >> seat;
    e.cancel(row, seat);

    e.display();

    return 0;
}