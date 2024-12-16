#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

// O(n), O(1)
struct DSU {
    vector<int> p;
    int comp;

    DSU(int n) { p.resize(n, -1); comp = n; }

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
        comp--; return true;
    }
};

void solve() {
    int n, m; cin >> n >> m;

    v<array<int, 2>> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i][0], a[i][1] = i;

    v<v<array<int, 2>>> adj(n);
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        x--, y--;
        adj[x].push_back(a[y]);
        adj[y].push_back(a[x]);
    }
    sort(a.begin(), a.end());

    DSU ds(n);
    v<set<array<int, 2>>> curr(n);
    v<int> alive(n);
    for (auto& [x, i] : a) {
        if (x == 0) alive[i] = 1;
        for (auto& [y, j] : adj[i]) {
            if (ds.size(i) < y or not alive[i]) {
                curr[ds.find(i)].insert({y, j});
                continue;
            }

            alive[j] = 1;
            int pa = ds.find(i), pb = ds.find(j);
            if (not ds.merge(i, j)) continue;
            if (pa == ds.find(i)) swap(pa, pb);
            curr[pb].insert(curr[pa].begin(), curr[pa].end());
            curr[pa].clear();
        }

        while (alive[i] and curr[ds.find(i)].size()) {
            auto [y, j] = *curr[ds.find(i)].begin();
            if (ds.size(i) < y) break;
            curr[ds.find(i)].erase(curr[ds.find(i)].begin());

            alive[j] = 1;
            int pa = ds.find(i), pb = ds.find(j);
            if (not ds.merge(i, j)) continue;
            if (pa == ds.find(i)) swap(pa, pb);
            curr[pb].insert(curr[pa].begin(), curr[pa].end());
            curr[pa].clear();
        }
    }
    cout << (ds.comp == 1 ? "YES" : "NO") << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}