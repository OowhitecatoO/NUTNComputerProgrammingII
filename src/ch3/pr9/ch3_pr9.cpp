#include <iostream>
#include <ctime>

using namespace std;

inline int rollOne() {
    return rand() % 6 + 1;
}

inline int rollTwo() {
    return rollOne() + rollOne();
}

bool playGame() {
    int takeOne = rollTwo();
    switch (takeOne) { // NOLINT(hicpp-multiway-paths-covered)
        case 7:
        case 11:
            return true;
        case 2:
        case 3:
        case 12:
            return false;
    }
    while (true) {
        int take = rollTwo();
        if (take == takeOne) return true;
        if (take == 7) return false;
    }
}

int main() {
    srand(time(nullptr));

    int times = 10000;
    int success = 0;
    for (int i = 0; i < times; ++i)
        if (playGame()) success++;

    cout << success / (double) times << endl;
}