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

struct query {
    int a, b, t, f, l, r;
};

void solve() {
    int n, m; cin >> n >> m;

    v<array<int, 3>> e(m);
    for (auto& [c, a, b] : e) {
        cin >> a >> b >> c;
        a--, b--;
    }
    sort(e.begin(), e.end());

    DSU ds(n);
    v<v<query>> q(m), nq(m);
    map<int, int> first;
    for (int i = 0; i < m; i++) {
        auto& [c, a, b] = e[i];
        if (not first.count(c))
            first[c] = i;
        if (not ds.merge(a, b))
            q[(m - 1) / 2].push_back({a, b, i, first[c], 0, m - 1});
    }

    int ans = 0, lgM = 18;
    for (int _ = 0; _ < lgM; _++) {
        fill(ds.p.begin(), ds.p.end(), -1);
        for (int i = 0; i < m; i++) {
            {
                auto& [c, a, b] = e[i];
                ds.merge(a, b);
            }
            while (q[i].size()) {
                auto& [a, b, t, f, l, r] = q[i].back();
                if (ds.same_set(a, b))
                    t = i, r = i - 1;
                else
                    l = i + 1;
                if (l <= r)
                    nq[(l + r) / 2].push_back(q[i].back());
                else
                    ans += t >= f;
                q[i].pop_back();
            }
        }
        swap(q, nq);
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