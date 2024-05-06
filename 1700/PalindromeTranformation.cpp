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
    int n, p; cin >> n >> p;
    string s; cin >> s;

    if (n == 1) {
        cout << 0 << nl;
        return;
    }

    auto get = [&](int i) {
        char a = s[i], b = s[n - i - 1];
        if (a < b) swap(a, b);
        return min(a - b, 'z' - a + 1 + b - 'a');
    };

    if (--p >= n / 2) p = n - p - 1;
    if ((n & 1) and p == n / 2) p--;

    int ans = 0;
    for (int i = 0; i < n / 2; i++)
        ans += get(i);

    int r = n / 2 - 1;
    while (r > p and s[r] == s[n - r - 1]) r--;

    int l = 0;
    while (l < p and s[l] == s[n - l - 1]) l++;

    int x = r + p - 2 * l;
    int y = 2 * r - p - l;

    cout << ans + min(x, y) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}