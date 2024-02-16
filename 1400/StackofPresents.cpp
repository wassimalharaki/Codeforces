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

    vi pos(n + 1), order(n);
    for (int i = 0; i < n; i++) {
        cin >> order[i];
        pos[order[i]] = i;
    }

    int ans = 0, max = -1;
    for (int i = 0; i < m; i++) {
        int a; cin >> a;
        ans++;
        if (pos[a] > max) {
            ans += 2 * (pos[a] - i);
            max = pos[a];
        }
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}