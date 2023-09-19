#include <bits/stdc++.h>

using namespace std;

#define loop(i, a, b) for (int i = a; i < b; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, a, b, moves, diff;

    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> a >> b;
        moves = 0;

        if (a > b) {
            diff = a - b;
            moves = diff / 10;
            if (diff % 10 != 0)
                moves++;
        }
        else if (a < b) {
            diff = b - a;
            moves = diff / 10;
            if (diff % 10 != 0)
                moves++;
        }
        cout << moves << endl;
    }

    return 0;
}