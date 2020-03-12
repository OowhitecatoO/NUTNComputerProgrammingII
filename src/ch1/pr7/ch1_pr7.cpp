#include <iostream>

using namespace std;

template<typename T>
void input(const string &name, T &var) {
    cout << name << "?";
    cin >> var;
}

double mph2met(double mph) {
    return mph * 10 / 6;
}

double calcCalPerMinute(double met, double weightInKG) {
    return 0.0175 * met * weightInKG;
}

int main() {
    double kg;
    input("kg", kg);

    const double minuteMax = 15;

    double mphNow = 4;
    int minuteInit = 3;

    double totalCal = calcCalPerMinute(mph2met(mphNow), kg) * minuteInit;

    for (int m = 0; m < minuteMax - minuteInit; ++m) {
        if (m % 4 == 0) mphNow += 2;

        totalCal += calcCalPerMinute(mph2met(mphNow), kg);
    }

    cout << totalCal << endl;
}