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

/*
whats the point of the awful definition
could have just said in all directions % n or m
*/

void solve() {
    int n, m, k; cin >> n >> m >> k;

    v<int> nums(k);
    for (int& a : nums) cin >> a;

    if (accumulate(all(nums), 0ll) < n * m) {
        cout << "NO" << nl;
        return;
    }

    //try vertically, try horizontally
    bool ok = 0;
    {
        int cols = 0;
        bool odd = 0;
        for (int& a : nums) {
            int x = a / n;
            if (x <= 1) continue;
            cols += x; odd |= x >= 3;
        }

        if (cols >= m) {
            if (m & 1)
                ok = odd;
            else
                ok = 1;
        }
    }

    {
        int rows = 0;
        bool odd = 0;
        for (int& a : nums) {
            int x = a / m;
            if (x <= 1) continue;
            rows += x; odd |= x >= 3;
        }

        if (rows >= n) {
            if (n & 1)
                ok |= odd;
            else
                ok = 1;
        }
    }
    cout << (ok ? "YES" : "NO") << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}