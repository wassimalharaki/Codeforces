#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n; cin >> n;
    string s, t; cin >> s >> t;

    v<int> ops;
    bool flip = 0, ok = 1;
    int a = 0, b = n - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (ok) {
            char c = s[b];
            if (flip)
                c = (c == '1' ? '0' : '1');

            if (c == t[i]) {
                b--;
                continue;
            }

            c = s[a];
            if (flip)
                c = (c == '1' ? '0' : '1');

            if (t[i] == c)
                ops.push_back(1);
            ops.push_back(i + 1);
            flip = !flip;
            ok = 0;
            a++;
        }
        else {
            char c = s[a];
            if (flip)
                c = (c == '1' ? '0' : '1');

            if (c == t[i]) {
                a++;
                continue;
            }

            c = s[b];
            if (flip)
                c = (c == '1' ? '0' : '1');

            if (t[i] == c)
                ops.push_back(1);
            ops.push_back(i + 1);
            flip = !flip;
            ok = 1;
            b--;
        }
    }

    cout << ops.size() << " ";
    for (int& a : ops)
        cout << a << " ";
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}