#include <bits/stdc++.h>
using namespace std;
#define int long long
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

void solve() {
    int n; cin >> n;

    v<int> a(n);
    for (int& x : a) cin >> x;

    v<array<int, 2>> ans;
    DSU ds(n);
    for (int i = n - 1; i > 0; i--) {
        v<map<int, int>> cnt(i);

        for (int j = 0; j < n; j++)
            cnt[a[j] % i][ds.find(j)] = j;

        for (int j = 0; j < n; j++) {
            auto& x = cnt[a[j] % i];
            if (x.size() == 1) continue;
            auto it = x.begin();
            if (x.begin() -> first == ds.find(j))
                it++;
            
            int k = it -> second;
            ds.merge(j, k);
            ans.push_back({j, k});
            break;
        }
    }

    if (ds.comp != 1) {
        cout << "NO" << nl;
        return;
    }
    
    cout << "YES" << nl;
    reverse(ans.begin(), ans.end());
    for (auto& [x, y] : ans)
        cout << x + 1 << " " << y + 1 << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}