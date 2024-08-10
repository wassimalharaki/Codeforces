#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

// O(n), O(1)
struct DSU {
    vector<int> p;

    DSU(int n) {
        p.resize(n, -1);
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
        return true;
    }
};

void solve() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    --a, --b;

    v<array<int, 2>> e(m);
    for (auto& [x, y] : e) {
        cin >> x >> y;
        --x, --y;
    }

    DSU da(n), db(n), dab(n);
    for (auto& [x, y] : e) {
        bool c = x != a and y != a;
        bool d = x != b and y != b;
        if (c) da.merge(x, y);
        if (d) db.merge(x, y);
        if (c and d) dab.merge(x, y);
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++)
        if (i != a and i != b)
            ans += max(0ll, n - da.size(i) - db.size(i) + dab.size(i)
                + da.same_set(i, b) + db.same_set(i, a) - 2);
    cout << ans / 2 << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}