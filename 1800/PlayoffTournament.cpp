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
0110 ?1 1
01101100 ??10 ?? 1
1 ?? 01?? 00110110
*/

void solve() {
    int k; cin >> k;
    int sz = 1 << k - 1, n = 1 << k;

    string s; cin >> s; s.push_back('x');
    reverse(s.begin(), s.end());

    v<int> a(n);
    auto fix = [&](int i) -> void {
        if (i >= sz)
            a[i] = s[i] == '?' ? 2 : 1;
        else if (s[i] == '?')
            a[i] = a[(i << 1)] + a[(i << 1) + 1];
        else if (s[i] == '0')
            a[i] = a[(i << 1) + 1];
        else
            a[i] = a[(i << 1)];
    };
    for (int i = n - 1; i > 0; i--) fix(i);

    int q; cin >> q;
    while (q--) {
        int i; cin >> i;
        char c; cin >> c;
        i = n - i;
        s[i] = c;
        while (i) fix(i), i >>= 1;
        cout << a[1] << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}