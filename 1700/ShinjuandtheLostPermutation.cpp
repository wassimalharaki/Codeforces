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

    if (count(a.begin(), a.end(), 1ll) != 1) {
        cout << "NO" << nl;
        return;
    }

    for (int i = 0; i < n; i++)
        if (a[i] == 1) {
            rotate(a.begin(), a.begin() + i, a.end());
            break;
        }

    int next = 2;
    for (int i = 1; i < n; i++)
        if (a[i] > next or a[i] - a[i - 1] > 1) {
            cout << "NO" << nl;
            return;
        }
        else if (a[i] == next)
            next++;

    cout << "YES" << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}