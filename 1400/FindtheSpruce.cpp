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

    vvi grid(n, vi(m)), prefix(n, vi(m + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            grid[i][j] = c == '*';
        }
        partial_sum(all(grid[i]), prefix[i].begin() + 1);
    }
    
    auto is_valid = [&](int i, int j) -> bool {
        return i >= 0 and j >= 0 and i < n and j < m;
    };
    
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int h = 0, w = 1;
            int r = i, c = j;
            bool ok = 1;
            while (ok) {
                if (not is_valid(r, c) or not is_valid(r, c + w - 1)) {
                    ok = 0;
                    break;
                }
                if (prefix[r][c + w] - prefix[r][c] != w)
                    ok = 0;
                w += 2;
                r++;
                c--;
                if (ok) h++;
            }
            ans += h;
        }
    cout << ans << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}