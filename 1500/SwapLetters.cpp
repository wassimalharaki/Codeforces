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
    string s, t; cin >> s >> t;

    int a = count(all(s), 'a') + count(all(t), 'a');
    int b = count(all(s), 'b') + count(all(t), 'b');

    if ((a & 1) or (b & 1)) {
        cout << -1 << nl;
        return;
    }

    v<int> ab, ba;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a' and t[i] == 'b')
            ab.push_back(i + 1);
        if (s[i] == 'b' and t[i] == 'a')
            ba.push_back(i + 1);
    }

    v<pair<int, int>> ans;
    int x = ab.size();
    while (x >= 2) {
        ans.push_back({ab[x - 1], ab[x - 2]});
        ab.pop_back(); ab.pop_back();
        x -= 2;
    }
    x = ba.size();
    while (x >= 2) {
        ans.push_back({ba[x - 1], ba[x - 2]});
        ba.pop_back(); ba.pop_back();
        x -= 2;
    }

    if (ab.size()) {
        ans.push_back({ab[0], ab[0]});
        ans.push_back({ab[0], ba[0]});
    }

    cout << ans.size() << nl;
    for (auto& p : ans)
        cout << p.first << " " << p.second << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}