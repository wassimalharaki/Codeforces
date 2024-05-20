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
    int k; cin >> k;
    
    v<v<int>> ans(3, v<int>(4));
    ans[0][0] = ans[2][2] = k + (1 << 17);
    ans[1][0] = ans[2][0] = ans[2][1] = (1 << 17);
    ans[0][1] = ans[0][2] = ans[1][2] = ans[2][3] = k;

    cout << "3 4" << nl;
    for (auto& x : ans) {
        for (int& y : x)
            cout << y << " ";
        cout << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}