#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

// O(n), O(1)
struct DSU {
    vector<int> p;

    DSU(int n) { p.resize(n, -1); }

    int find(int x) {
        return p[x] < 0 ? x : p[x] = find(p[x]);
    }

    int size(int x) { return - p[find(x)]; }

    bool same_set(int x, int y) {
        return find(x) == find(y);
    }

    bool merge(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (p[x] > p[y]) swap(x, y);
        p[x] += p[y]; p[y] = x;
        return true;
    }
};

void solve() {
    int n, k, d; cin >> n >> k >> d;

    queue<int> q;
    v<int> vis(n);
    for (int i = 0; i < k; i++) {
        int x; cin >> x; q.push(--x);
        vis[x] = 1;
    }

    v<v<int>> adj(n);
    v<array<int, 2>> e(n - 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        e[i] = {--a, --b};
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    DSU ds(n);
    while (q.size()) {
        int u = q.front();
        q.pop();

        for (int& i : adj[u])
            if (not vis[i]) {
                ds.merge(i, u);
                vis[i] = 1;
                q.push(i);
            }
    }

    v<int> ans;
    for (int i = 0; i < n - 1; i++)
        if (not ds.same_set(e[i][0], e[i][1]))
            ans.push_back(i + 1);

    cout << ans.size() << nl;
    for (int& x : ans)
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