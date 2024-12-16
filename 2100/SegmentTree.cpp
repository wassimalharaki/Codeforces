#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

// O(n), O(1)
struct DSU {
    vector<int> p;
    int comp;

    DSU(int n) { p.resize(n, -1); comp = n; }

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
        comp--; return true;
    }
};

void solve() {
    int n; cin >> n;

    v<int> a(2 * n);
    v<array<int, 2>> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i][0] >> b[i][1];
        a[--b[i][0]] = i, a[--b[i][1]] = i;
    }

    DSU ds(n);
    set<array<int, 2>> ok;
    for (int i = 0; i < 2 * n; i++)
        if (ok.count({i, a[i]}))
            ok.erase({i, a[i]});
        else {
            auto it = ok.lower_bound({i, -1});
            while (it != ok.end() and (*it)[0] < b[a[i]][1]) {
                if (not ds.merge(a[i], (*it)[1]))
                    return void(cout << "NO" << nl);
                it++;
            }
            ok.insert({i, a[i]});
            ok.insert({b[a[i]][1], a[i]});
        }
    cout << (ds.comp == 1 ? "YES" : "NO") << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}