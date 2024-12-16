#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

// O(n), O(1)
struct DSU {
    vector<int> p, mn;

    DSU(int n) {
        p.resize(n, -1);
        mn.resize(n);
        iota(mn.begin(), mn.end(), 0);
    }

    int find(int x) { return p[x] < 0 ? x : find(p[x]); }
    int get_min(int x) { return mn[find(x)]; }
    int size(int x) { return - p[find(x)]; }

    bool same_set(int x, int y) {
        return find(x) == find(y);
    }

    bool merge(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (p[x] > p[y]) swap(x, y);
        mn[x] = min(mn[x], mn[y]);
        p[x] += p[y]; p[y] = x;
        return true;
    }
};

const int mod = 1e9 + 7;

void solve() {
    int n, m; cin >> n >> m;

    DSU ds(m);
    v<int> ans;
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        v<int> a(k);
        for (int& x : a)
            cin >> x, x--;
        if (a.size() == 2) {
            auto [x, y] = make_pair(a[0], a[1]);
            if (ds.get_min(x) != -1 or ds.get_min(y) != -1) {
                if (ds.merge(x, y))
                    ans.push_back(i + 1);
                continue;
            }
        }
        else {
            auto x = a[0];
            if (ds.get_min(x) != -1) {
                ans.push_back(i + 1);
                ds.mn[ds.find(x)] = -1;
            }
        }
    }

    int sz = 1;
    for (int i = 0; i < (int) ans.size(); i++)
        sz = sz * 2 % mod;
    
    cout << sz << " " << ans.size() << nl;
    for (int& x : ans)
        cout << x << " ";
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}