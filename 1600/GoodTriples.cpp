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

v<int> ok(10);

void solve() {
    string s; cin >> s;
    int ans = 1;
    for (char& c : s)
        ans *= ok[c - '0'];
    cout << ans << nl;    
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ok[0] = 1;
    for (int i = 1; i < 10; i++)
        ok[i] = ok[i - 1] + i + 1;

    int T = 1;
    cin >> T;
    while (T--) solve();
}