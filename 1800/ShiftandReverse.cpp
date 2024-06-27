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
    int n; cin >> n;

    v<int> a(n);
    for (int& x : a) cin >> x;
    auto b = a;
    sort(b.begin(), b.end());

    int up = 0, down = 0;
    for (int i = 0; i < n; i++)
        if (a[i] < a[(i + 1) % n])
            up++;
        else if (a[i] > a[(i + 1) % n])
            down++;
            
    if (up > 1 and down > 1) {
        cout << -1 << nl;
        return;
    }

    auto get_up = [&]() -> int {
        int imin = 0;
        for (int i = 0; i < n; i++)
            if (a[i] > a[(i + 1) % n])
                imin = (i + 1) % n;
        return min((n - imin) % n, imin + 2);
    };

    auto get_down = [&]() -> int {
        int imin = 0;
        for (int i = 0; i < n; i++)
            if (a[i] < a[(i + 1) % n])
                imin = i;
        return min(n - imin, imin + 2);
    };

    if (up == 0)
        cout << 0 << nl;
    else if (up > 1)
        cout << get_up() << nl;
    else if (down > 1)
        cout << get_down() << nl;
    else
        cout << min(get_up(), get_down()) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}