#include <iostream>
#include <ctime>
#include <functional>
#include <conio.h>

using namespace std;

int rollOne() {
    int r = rand() % 6 + 1;
    cout << "Roll " << r << " !!" << endl;
    return r;
}

void playOne(int& total, const function<bool(int)>& keepRolling) {
    int sum = 0;
    int take = 0;

    while (true) {
        if (take == 0)
            take = rollOne();
        else {
            if (keepRolling(sum))
                take = rollOne();
            else break;
        }

        if (take == 1) {
            cout << "lost all score in this turn!" << endl;
            return;
        }
        sum += take;
        cout << "Holding " << sum << " in this turn!" << endl;
        if (total + sum >= 100) break;
    }

    total += sum;
}

int humanTurn(int humanTotalScore) {
    playOne(humanTotalScore, [](int) {
        while (true) {
            cout << "Roll again? Hold? (r/h) ";
            int chose = _getche();
            cout << endl;
            switch (chose) {
                case 'h':
                    return false;
                case 'r':
                    return true;
                default:
                    cout << "input Error" << endl;
            }
        }
    });
    return humanTotalScore;
}

int computerTurn(int computerTotalScore) {
    playOne(computerTotalScore, [](int sum) {
        return sum < 20;
    });
    return computerTotalScore;
}

int main() {
    srand(time(nullptr));

    int h_sc = 0, c_sc = 0;
    while (true) {
        cout << "Human turn!" << endl;
        h_sc = humanTurn(h_sc);
        cout << "Human score is " << h_sc << "!" << endl << endl;
        if (h_sc >= 100) {
            cout << "Human win!" << endl;
            break;
        }

        cout << "Computer turn!" << endl;
        c_sc = computerTurn(c_sc);
        cout << "Computer score is " << c_sc << "!" << endl << endl;
        if (c_sc >= 100) {
            cout << "Computer win!" << endl;
            break;
        }
    }
}
