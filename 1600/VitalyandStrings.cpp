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
    string s, t; cin >> s >> t;
    string ans = "No such string";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'z') continue;
        string u = s;
        u[i]++;
        fill(u.begin() + i + 1, u.end(), 'a');
        if (u < t) {
            ans = u;
            break;
        }
        u[i]--;
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}