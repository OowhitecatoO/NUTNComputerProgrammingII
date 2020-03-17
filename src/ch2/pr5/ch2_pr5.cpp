#include <iostream>
#include <map>
#include <set>
#include <regex>

using namespace std;

const regex REG_Number("\\w+");

class Token {
    static short getPriority(char op) {
        switch (op) {
            case '*':
            case '/':
                return 3;
            case '+':
            case '-':
                return 2;
            case '=':
                return 1;
            default:
                return 0;
        }
    }

public:
    const short priority;
    const bool isOperator;
    const string value;

    explicit Token(string value) :
            value(move(value)),
            isOperator(!regex_match(value, REG_Number)),
            priority(getPriority(value[0])) {}
};

class PuzzleKey {
    map<char, int *> m;
    vector<Token> postFix;
    string target;

    bool end = false;

public:
    vector<int> counter;

    explicit PuzzleKey(const string &fun) {
        target = fun;
        string s = fun;
        sort(s.begin(), s.end());
        s = regex_replace(s, regex("\\W"), "");
        s = regex_replace(s, regex("(\\w)\\1+"), "$1");

        counter.resize(s.size(), 0);

        for (int i = 0; i < s.size(); ++i) {
            m[s[i]] = counter.data() + i;
        }
        operator++();

        vector<Token> infix;
        infix.reserve(fun.size());

        for (auto[toFind, sm] = pair{fun, smatch()};
             regex_search(toFind, sm, regex("((\\w+)|([*+-/=]))"));
             toFind = sm.suffix().str()) {
            infix.emplace_back(sm[0]);
        }

        vector<Token> stack;
        stack.reserve(infix.size());

        for (const auto &token: infix) {
            if (token.isOperator) {
                while (!stack.empty() && stack.back().priority >= token.priority) {
                    postFix.push_back(stack.back());
                    stack.pop_back();
                }
                stack.push_back(token);
            } else {
                postFix.push_back(token);
            }
        }

        while (!stack.empty()) {
            postFix.push_back(stack.back());
            stack.pop_back();
        }

//        for (const auto &t : postFix)
//            cout << t.value << " ";
//        cout << endl;
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
//            doNext = false;
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

    bool check() {
        vector<int> stack;
        bool error = false;

        auto binOpt = [&stack](const function<int(int, int)> &block) {
            int b = stack.back();
            stack.pop_back();
            int a = stack.back();
            stack.pop_back();
            stack.push_back(block(a, b));
        };

        for (const auto &t: postFix) {
            if (error) break;
            if (!t.isOperator) {
                stack.push_back(operator[](t.value));
                continue;
            }

            switch (t.value[0]) {
                case '+':
                    binOpt([](int a, int b) { return a + b; });
                    break;
                case '-':
                    binOpt([](int a, int b) { return a - b; });
                    break;
                case '*':
                    binOpt([](int a, int b) { return a * b; });
                    break;
                case '/':
                    binOpt([](int a, int b) { return a / b; });
                    break;
                case '=':
                    binOpt([&error](int a, int b) {
                        if (a != b) error = true;
                        return b;
                    });
                    break;
            }

        }

        return !error;
    }

    void printAnswer() {
        for (auto k: m) {
            cout << k.first << ":" << *k.second << " ";
        }
        cout << endl;
        for (char c: target) {
            if (m.count(c) == 0)
                cout << c;
            else cout << *m[c];
        }
        cout << endl;
    }
};

int main() {

    string target = "TOO + TOO + TOO + TOO = GOOD";
    cout << target << endl;

    for (PuzzleKey p = PuzzleKey(target); p.hasNext(); ++p) {
        if (p.check())
            p.printAnswer();
    }

    cout << "Done!" << endl;

}