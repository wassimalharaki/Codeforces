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
    int n, k; cin >> n >> k;

    v<set<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }

    if (n == 1) {
        cout << 0 << nl;
        return;
    }
    else if (n == 2) {
        cout << 0 << nl;
        return;
    }

    queue<int> curr;
    for (int i = 1; i <= n; i++)
        if (adj[i].size() == 1)
            curr.push(i);
    
    int ans = n;
    while (curr.size() and k--) {
        int sz = curr.size();
        for (int i = 0; i < sz; i++) {
            int u = curr.front();
            ans--;
            curr.pop();
            for (int x : adj[u]) {
                adj[x].erase(u);
                if (adj[x].size() == 1)
                    curr.push(x);
            }
        }
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}