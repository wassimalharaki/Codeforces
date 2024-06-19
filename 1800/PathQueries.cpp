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

const int N = 2e5 + 1;

int get(int x) {
    return x * (x - 1) / 2;
}

void solve() {
    int n, m; cin >> n >> m;

    DSU ds(n);
    v<array<int, 3>> e(n - 1);
    for (auto& x : e) {
        cin >> x[1] >> x[2] >> x[0];
        x[1]--, x[2]--;
    }
    sort(e.begin(), e.end());

    int j = 0, curr = 0;
    v<int> ans(N);
    for (int i = 0; i < N; i++) {
        while (j < n - 1 and e[j][0] <= i) {
            curr -= get(ds.size(e[j][1]));
            curr -= get(ds.size(e[j][2]));
            ds.merge(e[j][1], e[j][2]);
            curr += get(ds.size(e[j][1]));
            j++;
        }
        ans[i] = curr;
    }

    while (m--) {
        int i; cin >> i;
        cout << ans[i] << " ";
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}