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

/*
if a 0 exists after n / 2,
first range is [1, pos], second range is [1, pos - 1]

if no 0 exists after n / 2
this means that it is all 1s
if 0 exists before n / 2
first range is [pos, n], second range is[pos + 1, n]
if no 0 exists before n / 2
this means that is is all 1s
first range is [1, n - 1], second range is [2, n]
*/

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    for (int i = n / 2; i < n; i++) {
        if (s[i] == '1') continue;
        cout << 1 << " " << i + 1 << " " << 1 << " " << i << nl;
        return;
    }

    for (int i = 0; i < (n + 1) / 2; i++) {
        if (s[i] == '1') continue;
        cout << i + 1 << " " << n << " " << i + 2 << " " << n << nl;
        return;
    }

    cout << 1 << " " << n - 1 << " " << 2 << " " << n << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}