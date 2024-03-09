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
    n += 2;

    cout << n + 2 * (n - 1) << nl;
    int x = 0, y = 0;
    for (int i = 0; i < n; i++)
        cout << x++ << " " << y++ << nl;
    n--;
    
    x = 1, y = 0;
    for (int i = 0; i < n; i++)
        cout << x++ << " " << y++ << nl;
    
    x = 0, y = 1;
    for (int i = 0; i < n; i++)
        cout << x++ << " " << y++ << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}