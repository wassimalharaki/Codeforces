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

const int mod = 1e9 + 7;
 
void solve() {
    int n; cin >> n;
    
    int ans = 0;
    for (int i = 2; i <= n; i++)
        ans = (ans * 3 + (i & 1 ? -3 : 3)) % mod;
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}