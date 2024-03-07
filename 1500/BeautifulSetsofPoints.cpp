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
    int n, m; cin >> n >> m;
    pair<int, int> p{0, m};

    auto valid = [&]() {
        return p.first <= n and p.second >= 0;
    };

    set<pair<int, int>> ans;
    while (1) {
        if (not valid())
            break;
        ans.insert(p);
        p.first++; p.second--;
    }
    
    cout << ans.size() << nl;
    for (pair<int, int> p : ans)
        cout << p.first << " " << p.second << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}