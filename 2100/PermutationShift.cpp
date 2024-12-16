#include <bits/stdc++.h>
using namespace std;
#define int long long
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

void solve() {
    int n, m; cin >> n >> m;

    v<int> a(n);
    for (int& x : a)
        cin >> x, x--;

    map<int, int> have;
    for (int i = 0; i < n; i++)
        have[(i - a[i] + n) % n]++;
    
    DSU ds(n);
    v<int> ans;
    for (auto& [k, z] : have) {
        if ((n - z) / 2 > m) continue;
        fill(ds.p.begin(), ds.p.end(), -1);

        for (int i = 0; i < n; i++)
            ds.merge(i, (a[i] + k) % n);
        int cnt = 0;
        for (int i = 0; i < n; i++)
            if (ds.find(i) == i)
                cnt += ds.size(i) - 1;
        if (cnt <= m) ans.push_back(k);
    }
    sort(ans.begin(), ans.end());

    cout << ans.size() << " ";
    for (int& x : ans)
        cout << x << " ";
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}