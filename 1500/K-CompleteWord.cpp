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
    int n, k; cin >> n >> k;
    string s; cin >> s;

    DSU ds(n);
    for (int i = 0; i < n / 2; i++)
        ds.merge(i, n - i - 1);
    for (int i = 0; i < n - k; i++)
        ds.merge(i, i + k);
    
    map<int, v<int>> comps;
    for (int i = 0; i < n; i++)
        comps[ds.find(i)].push_back(i);
    
    int ans = 0;
    for (auto& [key, indices] : comps) {
        v<int> letters(26);
        for (int i = 0; i < indices.size(); i++)
            letters[s[indices[i]] - 'a']++;
        ans += indices.size() - *max_element(all(letters));
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