#include <iostream>

using namespace std;

template<typename T>
void input(const string &name, T &var) {
    cout << name << "?";
    cin >> var;
}

double distCharge(double coefficient, double distance, double start) {
    double d = distance - start;
    return coefficient * (d > 0 ? d : 0);
}

double distCharge(double coefficient, double distance, double start, double end) {
    double d = (distance > end ? end : distance) - start;
    return coefficient * (d > 0 ? d : 0);
}

int main() {
    double km;
    double min;

    input("distance(km)", km);
    input("time(minutes)", min);

    double charges =
            distCharge(2, km, 0, 2) +
            distCharge(0.5, km, 2, 8) +
            distCharge(1, km, 8) +
            min * 0.2;

    cout << charges << endl;
}
