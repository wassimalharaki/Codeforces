#include <bits/stdc++.h>
using namespace std;
// #define int long long
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

const int N = 30;

void solve() {
    int n, m; cin >> n >> m;

    v<array<int, 3>> e(m);
    for (auto& [a, b, c] : e)
        cin >> a >> b >> c, a--, b--;
    
    int ans = 0;
    for (int i = N - 1; i >= 0; i--) {
        DSU ds(n);
        for (auto& [a, b, c] : e)
            if (!(c & (1 << i)))
                ds.merge(a, b);

        if (ds.comp != 1)
            ans += (1 << i);
        else {
            v<array<int, 3>> next;
            for (auto& [a, b, c] : e)
                if (!(c & (1 << i)))
                    next.push_back({a, b, c});
            e.swap(next);
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