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
    int n, q; cin >> n >> q;

    vvi grid(n, vi(2));
    int cnt = 0;
    while (q--) {
        int r, c; cin >> r >> c;
        swap(r, c);
        r--, c--;

        grid[r][c] = !grid[r][c];
        int ok = (grid[r][c] ? 1 : -1);
        for (int i = -1; i <= 1; i++)
            if (r + i >= 0 and r + i < n)
                if (grid[r + i][!c] == 1)
                    cnt += ok;
        cout << (cnt ? "No" : "Yes") << nl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}