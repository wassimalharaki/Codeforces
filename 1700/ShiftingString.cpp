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

    v<int> a(n);
    for (int& x : a) cin >> x, x--;

    v<v<int>> cycles;
    v<int> dead(n);
    for (int i = 0; i < n; i++) {
        if (dead[i]) continue;
        dead[i] = 1;
        int u = i;
        v<int> cycle{u};
        u = a[u];
        while (u != i) {
            dead[u] = 1;
            cycle.push_back(u);
            u = a[u];
        }
        cycles.push_back(cycle);
    }
    
    v<int> sizes;
    for (int i = 0; i < cycles.size(); i++) {
        string t;
        for (int& j : cycles[i])
            t += s[j];
        string u = t;
        int sz = 0;
        while (1) {
            rotate(u.begin(), u.begin() + 1, u.end());
            sz++;
            if (u == t) break;
        }
        sizes.push_back(sz);
    }

    int ans = 1;
    for (int& x : sizes)
        ans = lcm(ans, x);
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}