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

// O(n), O(log(n))
struct DSU {
    vector<int> p;
    int comp;

    DSU(int n) { p.resize(n, -1); comp = n; }

    int find(int x) { return p[x] < 0 ? x : p[x] = find(p[x]); }

    int size(int x) { return - p[find(x)]; }

    bool same_set(int x, int y) { return find(x) == find(y); }

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

    DSU ds(n);
    v<array<int, 2>> e(m);
    for (int i = 0; i < m; i++) {
        cin >> e[i][0] >> e[i][1];
        if (e[i][1] < e[i][0])
            swap(e[i][0], e[i][1]);
        ds.merge(--e[i][0], --e[i][1]);
    }
    sort(e.begin(), e.end());

    v<array<int, 2>> a{e[0]};
    for (int i = 1; i < m; i++)
        if (e[i][0] <= a.back()[1])
            a.back()[1] = max(a.back()[1], e[i][1]);
        else
            a.push_back(e[i]);
    
    int ans = 0;
    for (auto& [l, r] : a) {
        for (int i = l + 1; i <= r; i++)
            if (not ds.same_set(i, i - 1)) {
                ans++;
                ds.merge(i, i - 1);
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