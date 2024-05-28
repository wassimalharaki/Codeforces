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
    unsigned int x; cin >> x;
    v<int> ans;

    int start = 10;
    int y = __builtin_ctzll(bit_floor(x));
    while (y--)
        ans.push_back(start), start += 10;
    x -= bit_floor(x);
    start = 5;

    while (x) {
        y = __builtin_ctzll(bit_floor(x));
        ans.push_back(y * 10 + start);
        x -= bit_floor(x);
    }

    cout << ans.size() << nl;
    for (int& x : ans)
        cout << x << " ";
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}