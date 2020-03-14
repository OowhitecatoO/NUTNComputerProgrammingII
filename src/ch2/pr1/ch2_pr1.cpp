#include <iostream>

using namespace std;

template<typename T>
void input(const string &name, T &var) {
    cout << name << "?";
    cin >> var;
}

int main() {
    double stories;
    input("stories", stories);
    double base_first;
    input("base price of first floor", base_first);
    double amenities;
    input("amenities", amenities);
    double taxes;
    input("taxes", taxes);
    taxes /= 100;

    double sum = 0;
    double base_now = base_first;

    for (int i = 0; i < stories; ++i) {
        sum += base_now + amenities;
        base_now *= 1.02;
    }

    sum *= taxes;

    cout << sum << endl;
}