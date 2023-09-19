#include <bits/stdc++.h>

using namespace std;

#define loop(i, a, b) for (int i = a; i < b; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    string answ;
    loop(i, 0, t) {
        int a, b, moves = 0;
        cin >> a >> b;
        if (a < b) {
            moves = b - a;
            answ += to_string(moves) + "\n";
            continue;
        }
        double ratio = (double) a / b;
        double newA = b * ceil(ratio);
        moves = newA - a;
        answ += to_string(moves) + "\n";
    }

    cout << answ;

    return 0;
}