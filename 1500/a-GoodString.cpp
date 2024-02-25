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
    string s; cin >> s;

    auto ok = [&](int l, int r, char c, auto&& ok) -> int {
        if (l == r - 1)
            return s[l] != c;   

        int a = 0, b = 0;
        for (int i = l; i < (l + r) / 2; i++)
            if (s[i] != c) a++;
        
        for (int i = (l + r) / 2; i < r; i++)
            if (s[i] != c) b++;
        
        a += ok((l + r) / 2, r, c + 1, ok);
        b += ok(l, (l + r) / 2, c + 1, ok);
        return min(a, b);
    };
    cout << ok(0, n, 'a', ok) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}