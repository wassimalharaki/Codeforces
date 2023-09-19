#include <bits/stdc++.h>

using namespace std;

#define loop(i, a, b) for (int i = a; i < b; i++)

int biggestRound(int n) {
    string s = to_string(n);
    return (n / (int) pow(10, s.size() - 1)) * (int) pow(10, s.size() - 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, n, k, round;

    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n;
        string s = to_string(n);
        k = s.size();
        for (int i = 0; i < s.size(); i++)
            if (s[i] == '0')
                k--;
        cout << k << "\n";
        while (n != 0) {
            round = biggestRound(n);
            cout << round << " ";
            n -= round;
        }
        cout << "\n";
    }

    return 0;
}