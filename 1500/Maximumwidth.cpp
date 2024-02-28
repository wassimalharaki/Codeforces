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
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    
    v<int> first(m), last(m);
    int j = m - 1;
    for (int i = n - 1; i >= 0 and j >= 0; i--)
        if (s[i] == t[j])
            last[j--] = i;
    j = 0;
    for (int i = 0; i < n; i++)
        if (s[i] == t[j])
            first[j++] = i;
    
    int ans = 1;
    for (int i = 0; i < m - 1; i++)
        ans = max(ans, last[i + 1] - first[i]);
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}