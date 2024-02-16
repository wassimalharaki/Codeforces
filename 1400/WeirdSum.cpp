#include <bits/stdc++.h>

using namespace std;

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

#define int long long
#define INF LONG_LONG_MAX
#define nl '\n'
#define v vector
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define mp make_pair
#define F first
#define S second

using pii = pair<int, int>;
using vi = v<int>;
using vvi = v<vi>;
using vpii = v<pii>;

void solve() {
    int n, m; cin >> n >> m;

    vvi nums(n, vi(m));
    for (vi& a : nums)
        for (int& b : a)
            cin >> b;
    
    using mii = map<int, int>;
    using pmii = pair<mii, mii>;
    map<int, pmii> colors;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            colors[nums[i][j]].F[i]++;
            colors[nums[i][j]].S[j]++;
        }

    int ans = 0;
    for (auto& [key, p] : colors) {
        vpii row, col;
        for (auto& q : p.F) row.pb(q);
        for (auto& q : p.S) col.pb(q);
        int r = row.size(), c = col.size();

        vi pr(r + 1), wpr(r + 1);
        for (int i = 0; i < r; i++) {
            pr[i + 1] = pr[i] + row[i].S;
            wpr[i + 1] = wpr[i] + row[i].S * row[i].F;
        }

        vi pc(c + 1), wpc(c + 1);
        for (int i = 0; i < c; i++) {
            pc[i + 1] = pc[i] + col[i].S;
            wpc[i + 1] = wpc[i] + col[i].S * col[i].F;
        }

        for (int i = 0; i < r; i++)
            ans += row[i].S * (wpr[r] - wpr[i + 1] - row[i].F * (pr[r] - pr[i + 1]));
        for (int i = 0; i < c; i++)
            ans += col[i].S * (wpc[c] - wpc[i + 1] - col[i].F * (pc[c] - pc[i + 1]));
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}