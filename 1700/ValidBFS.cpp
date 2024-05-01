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

    v<set<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }

    v<int> order(n);
    for (int& a : order) cin >> a;

    if (order[0] != 1) {
        cout << "No";
        return;
    }

    int i = 1;
    queue<int> q;
    q.push(1);

    while (q.size()) {
        int u = q.front();
        q.pop();

        while (i < n and adj[u].count(order[i])) {
            adj[u].erase(order[i]);
            q.push(order[i++]);
        }
    }

    cout << (i == n ? "Yes" : "No");
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}