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
    int n; cin >> n;

    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        cnt[a]++;
    }

    map<int, int> occ;
    for (auto& [key, val] : cnt)
        occ[val]++;
    
    int dist = cnt.size(), ans = LONG_LONG_MAX;
    for (auto& [key, val] : occ) {
        dist -= val;
        ans = min(ans, n - key * (dist + val));
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