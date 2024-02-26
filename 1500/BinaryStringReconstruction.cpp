#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector
#define all(v) v.begin(), v.end()

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

void solve() {
    string s; cin >> s;
    int x; cin >> x;
    int n = s.size();

    string w(n, '1');
    for (int i = 0; i < n; i++)
        if (s[i] == '0') {
            if (i - x >= 0)
                w[i - x] = '0';
            if (i + x < n)
                w[i + x] = '0';
        }
    
    for (int i = 0; i < n; i++) {
        if (i - x < 0 and i + x >= n) {
            if (s[i] == '1') {
                cout << -1 << nl;
                return;
            }
        }
        else if (i - x < 0) {
            if (s[i] != w[i + x]) {
                cout << -1 << nl;
                return;
            }
        }
        else if (i + x >= n) {
            if (s[i] != w[i - x]) {
                cout << -1 << nl;
                return;
            }
        }
        else {
            if (s[i] == '0' and (w[i - x] == '1' or w[i + x] == '1')) {
                cout << -1 << nl;
                return;
            }

            if (s[i] == '1' and w[i - x] == '0' and w[i + x] == '0') {
                cout << -1 << nl;
                return;
            }
        }
    }
    cout << w << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}