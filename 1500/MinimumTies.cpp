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

    if (n & 1) {
        for (int i = n - 1; i > 0; i--)
            for (int j = 0; j < i; j++)
                cout << (j < n / 2 ? 1 : -1) << " ";
        cout << nl;
    }
    else {
        for (int i = n - 1; i > 0; i--)
            for (int j = 0; j < i; j++)
                if (j < n / 2 - 1)
                    cout << 1 << " ";
                else if (j == n / 2 - 1)
                    cout << 0 << " ";
                else
                    cout << -1 << " ";
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