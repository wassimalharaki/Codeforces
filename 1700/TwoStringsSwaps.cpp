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

    int ans = 0;
    for (int i = 0; i < (n + 1) / 2; i++) {
        if (i == n / 2) {
            if (s[i] != t[i])
                ans++;
        }
        else {
            string a{s[i], s[n - i - 1]};
            string b{t[i], t[n - i - 1]};

            if (b[0] == b[1])
                ans += a[0] != a[1];
            else if (a[0] == b[0])
                ans += a[1] != b[1];
            else if (a[0] == b[1])
                ans += a[1] != b[0];
            else if (a[1] == b[0])
                ans++;
            else if (a[1] == b[1])
                ans++;
            else
                ans += 2;
        }
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}