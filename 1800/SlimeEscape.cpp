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
    int n, k; cin >> n >> k;

    v<int> a(n);
    for (int& x : a) cin >> x;

    if (k == 1 or k == n) {
        cout << "YES" << nl;
        return;
    }
    k--;

    int curr = a[k], l = k - 1, r = k + 1;
    int min_left, val_left, min_right, val_right;

    auto fix_left = [&]() {
        min_left = val_left = 0;
        while (l >= 0) {
            val_left += a[l--];
            min_left = min(min_left, val_left);
            if (val_left >= 0) break;
        }
    };
    fix_left();

    auto fix_right = [&]() {
        min_right = val_right = 0;
        while (r < n) {
            val_right += a[r++];
            min_right = min(min_right, val_right);
            if (val_right >= 0) break;
        }
    };
    fix_right();

    while (1) {
        if (l < 0 and curr + min_left >= 0) {
            cout << "YES" << nl;
            return;
        }
        if (r >= n and curr + min_right >= 0) {
            cout << "YES" << nl;
            return;
        }

        if (curr + min_left >= 0) {
            curr += val_left;
            fix_left();
        }
        else if (curr + min_right >= 0) {
            curr += val_right;
            fix_right();
        }
        else {
            cout << "NO" << nl;
            return;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}