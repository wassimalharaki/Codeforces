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

    if (n < 5) {
        cout << n * (n - 1) / 2 << nl;
        return;
    }

    string s = to_string(n);
    if (s[0] >= '5') {
        string t = "5" + string(s.size() - 1, '0');
        int x = stoll(t);
        cout << n - x + 1 - (s == string(s.size(), '9')) << nl;
    }
    else {
        int y = stoll(string(s.size() - 1, '9'));
        int x = stoll("5" + string(s.size() - 2, '0'));

        int ans = 0, z = 1;
        while (x <= n) {
            int r = min(n, x + y);
            ans += z * (r - x + 1) - (r >= x + y / 2);
            x = r + 1, z++;
        }
        cout << ans << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}