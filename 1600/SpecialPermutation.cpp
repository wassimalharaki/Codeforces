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

//8 4 2 6 9 7 5 3 1
//10 6 2 4 8 11
//12 8 4 2 6 10 13 

void solve() {
    int n; cin >> n;
     
    if (n <= 3)
        cout << -1 << nl;
    else if (n & 1) {
        int x = n - 1;
        while (x >= 2) {
            cout << x << " ";
            x -= 4;
        }
        x = (x == 0 ? 2 : 4);
        while (x < n) {
            cout << x << " ";
            x += 4;
        }
        x = n;
        while (x >= 1) {
            cout << x << " ";
            x -= 2;
        }
        cout << nl;
    }
    else {
        for (int i = 2; i <= n; i += 2)
            cout << i << " ";
        cout << n - 3 << " " << n - 1 << " ";
        for (int i = n - 5; i >= 1; i -= 2)
            cout << i << " ";
        cout << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}