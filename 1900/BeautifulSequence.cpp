#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (b + 1 < a or c + 1 < d) {
        cout << "NO" << nl;
        return;
    }

    if (b < a) {
        if (c or d)
            cout << "NO" << nl;
        else {
            cout << "YES\n0 ";
            for (int i = 0; i < b; i++)
                cout << "1 0 ";
            cout << nl;
        }
        return;
    }

    if (c < d) {
        if (a or b)
            cout << "NO" << nl;
        else {
            cout << "YES\n3 ";
            for (int i = 0; i < c; i++)
                cout << "2 3 ";
            cout << nl;
        }
        return;
    }
    
    b -= a, c -= d;
    if (abs(b - c) > 1) {
        cout << "NO" << nl;
        return;
    }
    
    cout << "YES" << nl;
    if (b - c == 1) {
        cout << "1 ";
        for (int i = 0; i < a; i++)
            cout << "0 1 ";
        for (int i = 0; i < c; i++)
            cout << "2 1 ";
        for (int i = 0; i < d; i++)
            cout << "2 3 ";
    }
    else if (c - b == 1) {
        for (int i = 0; i < a; i++)
            cout << "0 1 ";
        for (int i = 0; i < b; i++)
            cout << "2 1 ";
        for (int i = 0; i < d; i++)
            cout << "2 3 ";
        cout << "2 ";
    }
    else {
        for (int i = 0; i < a; i++)
            cout << "0 1 ";
        for (int i = 0; i < b; i++)
            cout << "2 1 ";
        for (int i = 0; i < d; i++)
            cout << "2 3 ";
    }
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}