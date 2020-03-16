#include <iostream>
#include <map>
#include <set>
#include <regex>

using namespace std;

class PuzzleKey {
    map<char, int *> m;

    bool end = false;

public:
    vector<int> counter;

    explicit PuzzleKey(string fun) {
        sort(fun.begin(), fun.end());
        string s = regex_replace(fun, regex("\\W"), "");
        s = regex_replace(s, regex("(\\w)\\1+"), "$1");

        counter.resize(s.size(), 0);

        for (int i = 0; i < s.size(); ++i) {
            m[s[i]] = counter.data() + i;
        }

//        operator++();
//
//        counter[2] = 3;
//
//        for (auto it : m) {
//            cout << it.first << ":" << *it.second << endl;
//        }
    }

    bool hasNext() {
        return !end;
    }

    void operator++() {
        if (end) return;

        bool doNext = true;
        while (doNext) {

            int idx = 0;
            bool up;
            do {
                if (idx == counter.size() && (end = true)) return;
                up = false;
                if (counter[idx] == 9) {
                    up = true;
                    counter[idx++] = 0;
                } else counter[idx]++;
            } while (up);

            set<int> check(counter.begin(), counter.end());
            if (check.size() == counter.size()) doNext = false;
            doNext = false;
        }
    }

    int operator[](const string &token) {
        int sum = 0;
        for (char c : token) {
            sum *= 10;
            sum += *m[c];
        }

//        for (auto i : counter) cout << i << " ";
//        cout << endl;
//        cout << token << " " << sum << endl;
        return sum;
    }

    void printFormat(const string &format) {
        for (char c: format) {
            int *find = m[c];
            if (find) cout << *find;
            else cout << c;
        }
        cout << endl;
    }
};

int main() {

    string target = "TOO + TOO + TOO + TOO = GOOD";
    cout << target << endl;

    for (PuzzleKey p = PuzzleKey(target); p.hasNext(); ++p) {
        if (p["TOO"] + p["TOO"] + p["TOO"] + p["TOO"] == p["GOOD"])
            p.printFormat(target);
    }

    cout << "Done!" << endl;

}