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
    string s; cin >> s;

    v<int> dead(n);
    for (int i = 0; i < s.size(); i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (s[j] == s[i] + 1)
                dead[j] = 1;
            if (s[j] + 1 == s[i])
                dead[i] = 1;
            if (s[j] < s[i] - 1) break;
            if (not dead[j]) break;
        }
    }

    int ans = 0;
    for (auto b : dead)
        ans += b;
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}