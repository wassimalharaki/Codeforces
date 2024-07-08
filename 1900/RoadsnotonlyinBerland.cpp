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

// O(n), O(1)
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
    int n; cin >> n;

    DSU ds(n);
    v<array<int, 2>> free;
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        if (not ds.merge(a, b))
            free.push_back({a, b});
    }

    v<int> comps;
    for (int i = 0; i < n; i++)
        if (ds.p[i] < 0)
            comps.push_back(i);
    
    v<array<int, 4>> ans;
    for (int i = 0; i < (int) comps.size() - 1; i++)
        ans.push_back({free[i][0], free[i][1], comps[i], comps[i + 1]});
    
    cout << ans.size() << nl;
    for (auto& x : ans)
        cout << x[0] + 1 <<  " " << x[1] + 1 << " "
             << x[2] + 1 << " " << x[3] + 1 << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}