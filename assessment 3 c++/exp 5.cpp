#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <stdexcept>
using namespace std;

class Time {
    int seconds;

public:
    Time(int s = 0) : seconds(s) {}

    // Postfix increment
    Time operator++(int) {
        Time old = *this;
        ++seconds;
        return old;
    }

    // Prefix increment
    Time& operator++() {
        ++seconds;
        return *this;
    }

    bool operator==(const Time& t) const {
        return seconds == t.seconds;
    }

    bool operator<(const Time& t) const {
        return seconds < t.seconds;
    }

    void display() const {
        int h = seconds / 3600;
        int m = (seconds % 3600) / 60;
        int s = seconds % 60;

        cout << setfill('0')
             << setw(2) << h << ":"
             << setw(2) << m << ":"
             << setw(2) << s
             << setfill(' ') << '\n';
    }
};

class Playlist {
    vector<string> songs;

public:
    void addSong(const string& song) {
        songs.push_back(song);
    }

    string& operator[](int index) {
        if (index < 0 || index >= (int)songs.size())
            throw out_of_range("Playlist index out of range");

        return songs[index];
    }

    const string& operator[](int index) const {
        if (index < 0 || index >= (int)songs.size())
            throw out_of_range("Playlist index out of range");

        return songs[index];
    }
};

int main() {
    int s, n, index;

    cout << "Enter initial time in seconds: ";
    cin >> s;

    Time t(s);

    Time a = t++;
    Time b = ++t;

    cout << "Postfix value: ";
    a.display();

    cout << "Prefix value: ";
    b.display();

    cout << "Current time: ";
    t.display();

    cout << "Enter number of songs: ";
    cin >> n;

    Playlist p;

    cin.ignore();

    for (int i = 0; i < n; i++) {
        string song;
        getline(cin, song);
        p.addSong(song);
    }

    cout << "Enter playlist index: ";
    cin >> index;

    try {
        cout << "Selected song: " << p[index] << '\n';
    }
    catch (const out_of_range& e) {
        cout << "Error: " << e.what() << '\n';
    }

    return 0;
}