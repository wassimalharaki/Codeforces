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
    int a, b; cin >> a >> b;

    if ((a | b) == b) {
        cout << 1 << nl;
        return;
    }
    
    int ans = b - a;    
    int x = a, y = b, curr = 0;
    for (int i = 1; i <= b - a; i++) {
        curr++, x++;
        if ((x | y) == y) {
            curr++;
            ans = min(ans, curr);
        }
    }

    x = a, y = b, curr = 0;
    for (int i = 1; i <= b - a; i++) {
        curr++, y++;
        if ((x | y) == y) {
            curr++;
            ans = min(ans, curr);
        }
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