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
    int n, l, r; cin >> n >> l >> r;

    bool last = 0;
    if (r == n * (n - 1) + 1)
        last = 1, r--;

    int x = 0, p = n;
    for (int i = 1; i < n; i++)
        if (l <= (x += 2 * (n - i))) {
            p = i;
            break;
        }
    x -= 2 * (n - p);

    if (p == n) {
        cout << 1 << nl;
        return;
    }

    l--, r--;
    bool alt = l & 1;
    array<int, 2> curr{p, p + (l - x) / 2 + 1};
    while (l <= r) {
        cout << curr[alt] << " ";
        alt = !alt;
        if (alt == 0) {
            if (curr[1] + 1 <= n)
                curr[1]++;
            else
                curr[1] = ++curr[0] + 1;
        }
        r--;
    }
    cout << (last ? "1" : "") << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}