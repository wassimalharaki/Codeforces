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

struct DSU {
    vector<int> p;

    DSU(int n) { p = vector<int>(n, -1); }

    int find(int x) { return p[x] < 0 ? x : p[x] = find(p[x]); }

    int size(int x) { return - p[find(x)]; }

    bool same_set(int x, int y) { return find(x) == find(y); }

    bool merge(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (p[x] > p[y]) swap(x, y);
        p[x] += p[y]; p[y] = x;
        return true;
    }
};

void solve() {
    int n; cin >> n;

    map<int, int> valid;
    DSU ds(n + 1);
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        valid[a]++, valid[b]++;
        ds.merge(a, b);
    }

    for (auto& [key, val] : valid) 
        if (val != 2) {
            cout << "NO" << nl;
            return;
        }
    
    for (int i = 1; i <= n; i++)
        if (ds.size(i) & 1) {
            cout << "NO" << nl;
            return;
        }

    cout << "YES" << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}