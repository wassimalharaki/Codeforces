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

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;

    v<int> l(k), r(k);
    for (int& a : l) cin >> a;
    for (int& a : r) cin >> a;
    int q; cin >> q;
    v<map<pair<int, int>, int>> revs(k);
    while (q--) {
        int x; cin >> x;
        int i = --upper_bound(all(l), x) - l.begin();
        int a = min(x, r[i] + l[i] - x);
        int b = max(x, r[i] + l[i] - x);
        revs[i][make_pair(a, b)]++;
    }
    
    for (int i = 0; i < k; i++) {
        auto& map = revs[i];
        if (map.empty()) continue;
        int a = map.begin() -> first.first, b = map.begin() -> first.second;
        int count = 0;
        while (a < b) {
            count += map[make_pair(a, b)];
            if (count & 1)
                swap(s[a - 1], s[b - 1]);
            a++, b--;
        }
    }
    cout << s << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}