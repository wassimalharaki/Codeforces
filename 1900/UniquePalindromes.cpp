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
    int n, k; cin >> n >> k;

    v<array<int, 2>> a(k);
    for (auto& x : a)
        cin >> x[0];
    for (auto& x : a)
        cin >> x[1];

    for (auto& x : a)
        if (x[1] > x[0]) {
            cout << "NO" << nl;
            return;
        }
    for (int i = 0; i < k - 1; i++)
        if (a[i + 1][1] - a[i][1] > a[i + 1][0] - a[i][0]) {
            cout << "NO" << nl;
            return;
        }

    int j = 0;
    string bad = "ayz";
    string s = string(a[0][1] - 2, 'a') + "yz";
    while (s.size() < a[0][0])
        s.push_back(bad[j++ % 3]);

    s += string(s.size() - a[0][0], 'a');
    for (int i = 1; i < k; i++) {
        int m = a[i][0] - a[i - 1][0];
        int p = a[i][1] - a[i - 1][1];
        s += string(p, char('a' + i));
        m -= p;
        for (int l = 0; l < m; l++)
            s.push_back(bad[j++ % 3]);
    }
    cout << "YES" << nl << s << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}