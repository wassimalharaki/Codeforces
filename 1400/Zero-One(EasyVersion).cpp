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
    int n, x, y; cin >> n >> x >> y;
    string s, t; cin >> s >> t;
    x = min(x, 2 * y);

    vi fix;
    for (int i = 0; i < n; i++)
        if (s[i] != t[i])
            fix.pb(i);
    n = fix.size();

    if (n & 1)
        cout << -1 << nl;
    else if (n == 2)
        cout << (fix[0] + 1 == fix[1] ? x : y) << nl;
    else
        cout << (n >> 1) * y << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}