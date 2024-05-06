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

void solve() {
    int n, m; cin >> n >> m;

    v<string> s(n);
    for (auto& t : s) cin >> t;

    auto check = [&](string& t) {
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < m; j++)
                cnt += t[j] != s[i][j];
            if (cnt > 1) return 0;
        }
        return 1;
    };

    v<set<char>> diff(m);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            diff[i].insert(s[j][i]);
            
    bool ok = 1;
    for (int i = 0; i < m; i++) {
        if (diff[i].size() == 1) continue;
        ok = 0;
        for (char c : diff[i]) {
            string t;
            for (int j = 0; j < n; j++)
                if (s[j][i] != c) {
                    t = s[j];
                    break;
                }
            t[i] = c;
            if (check(t)) {
                cout << t << nl;
                return;
            }
        }
    }

    cout << (ok ? s[0] : "-1") << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}