#include <iostream>

using namespace std;

const int n = 49; // 3 + 49 * 2 = 101

bool not_p[n - 1] = {false};
// start at 3, index * 2 + 3 => n

int main() {
//     cout << 2 << " ";
    for (int i = 0; i < n; ++i) {
        if (not_p[i]) continue;
        int p = 3 + i * 2;
        cout << p << " ";

        for (int j = i + p; j < n; j += p) not_p[j] = true;
    }
}