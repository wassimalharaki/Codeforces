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

// O(n), O(log(n))
struct DSU {
    vector<int> p;
    int comp;

    DSU(int n) { p = vector<int>(n, -1); comp = n; }

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
    v<set<int>> adj(n);
    for (int i = 0, a; i < n; i++) {
        cin >> a; a--;
        ds.merge(i, a);
        adj[i].insert(a);
        adj[a].insert(i);
    }

    set<int> done;
    for (int i = 0; i < n; i++)
        if (adj[i].size() == 1)
            done.insert(ds.find(i));
    
    cout << ds.comp - max(0ll, (int) done.size() - 1) << " " << ds.comp << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}