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

    v<array<int, 3>> a(n);
    for (auto& x : a) cin >> x[0];
    for (auto& x : a) cin >> x[1];
    for (auto& x : a) cin >> x[2];

    v<v<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y; cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int u = -1;
    for (int i = 0; i < n; i++) {
        if (adj[i].size() > 2) {
            cout << -1 << nl;
            return;
        }
        if (adj[i].size() == 1) u = i;
    }

    int prev = -1;
    v<int> ord(n);
    for (int i = 0; i < n; i++) {
        ord[i] = u;
        int next = -1;
        for (auto& j : adj[u])
            if (j != prev)
                next = j;
        prev = u, u = next;
    }

    v<int> ok{0, 1, 2};
    auto check = [&]() -> int {
        int x = 0;
        for (int i = 0; i < n; i++)
            x += a[ord[i]][ok[i % 3]];
        return x;
    };

    v<int> best;
    int ans = 1e18;
    do {
        int curr = check();
        if (curr < ans) {
            ans = curr;
            best = ok;
        }
    } while (next_permutation(ok.begin(), ok.end()));

    v<int> fix(n);
    for (int i = 0; i < n; i++)
        fix[ord[i]] = best[i % 3] + 1;
    
    cout << ans << nl;
    for (int& x : fix)
        cout << x << " ";
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}