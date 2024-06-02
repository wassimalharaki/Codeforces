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

/*
8 8 8 1


*/

void solve() {
    int n; cin >> n;

    v<int> a(n);
    int sum = 0, mx = 0;
    for (int& x : a) {
        cin >> x;
        mx = max(mx, x);
        sum += x;
    }
    
    if (2 * mx > sum or (sum & 1))
        cout << "T" << nl;
    else
        cout << "HL" << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}