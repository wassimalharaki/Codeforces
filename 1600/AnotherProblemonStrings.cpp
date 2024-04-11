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
    int k; cin >> k;
    string s; cin >> s;
    int n = s.size();

    v<int> ind{-1};
    for (int i = 0; i < n; i++)
        if (s[i] == '1')
            ind.push_back(i);
    ind.push_back(n);

    n = ind.size();
    int ans = 0;
    if (k == 0)
        for (int i = 1; i < n; i++) {
            int x = ind[i] - ind[i - 1] - 1;
            ans += x * (x + 1) / 2;
        }
    else
        for (int i = 1; i + k < n; i++)
            ans += (ind[i] - ind[i - 1]) * (ind[i + k] - ind[i + k - 1]);
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}