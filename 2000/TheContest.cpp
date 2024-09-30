#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    array<int, 3> n;
    cin >> n[0] >> n[1] >> n[2];
    int m = accumulate(n.begin(), n.end(), 0ll);

    array<v<int>, 3> a, pref;
    for (int i = 0; i < 3; i++) {
        a[i].resize(m + 1);
        pref[i].resize(m + 2);
        for (int j = 0; j < n[i]; j++) {
            int x; cin >> x; a[i][x]++;
        }
        partial_sum(a[i].begin(), a[i].end(), pref[i].begin() + 1);
    }

    v<int> suff(m + 2, LLONG_MAX);
    for (int i = m; i >= 0; i--)
        suff[i] = min(suff[i + 1], pref[1][m + 1]
            - pref[1][i + 1] + pref[2][i + 1]);
    
    int ans = LLONG_MAX;
    for (int i = 0; i <= m; i++)
        ans = min(ans, pref[0][m + 1] - pref[0][i + 1]
            + pref[1][i + 1] + suff[i]);
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}