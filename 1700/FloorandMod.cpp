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

int get(int x, int a, int b) {
    b = min(b, x);

    int ans = 0;
    while (a * a <= x and a <= b)
        ans += x / a++;
    
    while (a <= b) {
        int c = x / a;
        int l = a;
        int r = min(b, x / c);
        ans += (r - l + 1) * c;
        a = r + 1;
    }
    return ans;
}

void solve() {
    int x, y; cin >> x >> y;

    int lo = 0, hi = y, k;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        if (x / (mid + 1) >= mid - 1)
            k = mid, lo = mid + 1;
        else
            hi = mid - 1;
    }

    cout << (k - 1) * k / 2 + get(x, k + 2, y + 1) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}