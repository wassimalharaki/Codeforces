#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

// O(n), O(1)
struct DSU {
    vector<int> p;
    int comp;

    DSU(int n) {
        p.resize(n, -1); comp = n;
    }

    int find(int x) {
        return p[x] < 0 ? x : p[x] = find(p[x]);
    }

    int size(int x) {
        return - p[find(x)];
    }

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
    sort(a.begin(), a.end());

    v<array<int, 3>> e(m);
    for (auto& [x, y, z] : e) {
        cin >> y >> z >> x;
        y--, z--;
    }
    
    for (int i = 1; i < n; i++)
        e.push_back({a[0][0] + a[i][0], a[0][1], a[i][1]});
    sort(e.begin(), e.end());

    DSU ds(n);
    int ans = 0;
    for (auto& [w, x, y] : e)
        if (ds.merge(x, y)) ans += w;
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}