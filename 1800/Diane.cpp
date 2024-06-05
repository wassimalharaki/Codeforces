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
    int n; cin >> n;
    if (n == 1)
        cout << 'a' << nl;
    else
        cout << string(n / 2 - 1, 'a') 
            << 'b' << (n & 1 ? "c" : "")
            << string(n / 2, 'a') << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}