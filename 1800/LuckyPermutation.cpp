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
    int n; cin >> n;

    v<int> a(n), pos(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }

    int ans = 1;
    DSU ds(n + 1);
    for (int i = 0; i < n; i++)
        if (a[i] != i + 1) {
            swap(a[pos[i + 1]], a[i]);
            ds.merge(pos[a[pos[i + 1]]], pos[i + 1]);
            swap(pos[a[pos[i + 1]]], pos[i + 1]);
            ans++;
        }
    
    for (int i = 0; i < n - 1; i++)
        if (ds.same_set(i, i + 1)) {
            ans -= 2;
            break;
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