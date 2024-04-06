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
    int n; cin >> n;
    string s; cin >> s;

    int ones = count(all(s), '1');
    if (s[0] != '1' or s[n - 1] != '1' or (ones & 1)) {
        cout << "NO" << nl;
        return;
    }

    bool alt = 0;
    string a, b;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            if (cnt >= ones / 2) {
                a += ')';
                b += ')';
            }
            else {
                a += '(';
                b += '(';
                cnt++;
            }
        }
        else {
            if (alt) {
                a += ')';
                b += '(';
                alt = 0;
            }
            else {
                a += '(';
                b += ')';
                alt = 1;
            }
        }
    }
            
    cout << "YES" << nl;
    cout << a << nl << b << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}