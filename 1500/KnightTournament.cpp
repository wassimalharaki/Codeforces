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
    int n, m; cin >> n >> m;

    v<int> ans(n + 1, 0);
    set<int> alive;
    for (int i = 1; i <= n; i++)
        alive.insert(i);
    
    for (int i = 0; i < m; i++) {
        int l, r, x; cin >> l >> r >> x;

        auto it = alive.lower_bound(l);
        v<int> kill;
        while (it != alive.end() and *it <= r) {
            if (*it == x) {
                it++;
                continue;
            }
            ans[*it] = x;
            kill.push_back(*it);
            it++;
        }

        for (int& a : kill) alive.erase(a);
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}