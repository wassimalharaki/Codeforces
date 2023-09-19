#include <bits/stdc++.h>

using namespace std;

#define loop(i, a, b) for (int i = a; i < b; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, points, min, max, amazing = 0;

    cin >> n >> points;
    max = min = points;

    for (int i = 1; i < n; i++) {
        cin >> points;

        if (points > max) {
            amazing++;
            max = points;
        }
        if (points < min) {
            amazing++;
            min = points;
        }
    }

    cout << amazing;

    return 0;
}