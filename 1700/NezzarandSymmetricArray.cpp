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

    v<int> a(n << 1);
    for (int& x : a) cin >> x;
    sort(a.begin(), a.end());

    int p = -1, cnt = 0;
    for (int i = 0; i < 2 * n; i++)
        if (a[i] == p) {
            if (++cnt > 2) {
                cout << "NO" << nl;
                return;
            }
        }
        else
            p = a[i], cnt = 1;

    a.resize(unique(a.begin(), a.end()) - a.begin());
    if (a.size() != n or (a[0] & 1)) {
        cout << "NO" << nl;
        return;
    }

    int sum = a[0] / 2, curr = 1, prev = 1;
    for (int i = 1; i < n; i++) {
        int diff = a[i] - a[i - 1];
        if (diff % (2 * i)) {
            cout << "NO" << nl;
            return;
        }
        prev += diff / (2 * i);
        curr += prev;
    }

    if (curr > sum)
        cout << "NO" << nl;
    else
        cout << ((sum - curr) % n ? "NO" : "YES") << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}