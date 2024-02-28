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
    int a, b, c; cin >> a >> b >> c;
    string s;
    if (c)
        s += string(c + 1, '1');
    if (a)
        s += string(a + 1, '0');
    if (b) {
        if (a == 0 and c == 0)
            for (int i = 0; i <= b; i++)
                s += (i & 1 ? '1' : '0');
        else if (a == 0)
            for (int i = 0; i < b; i++)
                s += (i & 1 ? '1' : '0');
        else
            for (int i = 0; i < b - (c > 0); i++)
                s += (i & 1 ? '0' : '1');
    }
    cout << s << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}