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

    if (set<int>(a.begin(), a.end()).size() != n) {
        cout << "NO" << nl;
        return;
    }

    v<v<int>> cnt(n + 1, v<int>(n + 1));
    for (int i = 2; i <= n; i++) {
        for (int& x : a)
            cnt[i][x % i]++;
        if (*min_element(cnt[i].begin(), cnt[i].begin() + i) > 1) {
            cout << "NO" << nl;
            return;
        }
    }
    cout << "YES" << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}