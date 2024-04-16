#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector
#define all(v) v.begin(), v.end()

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n, m; cin >> n >> m;

    v<int> a(n), b(n), c(m), ans(m), bad;
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;
    for (int& x : c) cin >> x;

    v<v<int>> need(n + 1), fixed(n + 1);
    for (int i = 0; i < n; i++)
        if (a[i] == b[i])
            fixed[b[i]].push_back(i);
        else
            need[b[i]].push_back(i);

    for (int i = 0; i < m; i++) {
        if (need[c[i]].size()) {
            ans[i] = need[c[i]].back();
            fixed[c[i]].push_back(need[c[i]].back());
            need[c[i]].pop_back();
            while (bad.size()) {
                ans[bad.back()] = ans[i];
                bad.pop_back();
            }
        }
        else if (fixed[c[i]].size()) {
            ans[i] = fixed[c[i]].back();
            while (bad.size()) {
                ans[bad.back()] = ans[i];
                bad.pop_back();
            }
        }
        else
            bad.push_back(i);
    }

    bool ok = bad.empty();
    for (auto& a : need)
        ok &= a.empty();

    if (not ok)
        cout << "NO" << nl;
    else {
        cout << "YES" << nl;
        for (int& a : ans)
            cout << a + 1 << " ";
        cout << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}