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

int get(int mid) {
    int x = 0, y = mid;
    int a = 1;
    while (y) {
        int rem = y % 10;
        x += (rem - (rem >= 4)) * a;
        a *= 9;
        y /= 10;
    }
    return x;
}

void solve() {
    int k; cin >> k;

    int lo = 0, hi = 1e18;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        if (get(mid) >= k)
            hi = mid - 1;
        else
            lo = mid + 1;
    }
    string ans = to_string(lo);
    for (char& c : ans) if (c == '4') c = '3';
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}