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

void out(vvi& grid) {
    for (vi& a : grid) {
        for (int& b : a)
            cout << b << " ";
        cout << nl;
    }
}

void solve() {
    int n, m; cin >> n >> m;

    vvi grid(n, vi(m));
    if (!(n & 1)) {
        grid[0][0] = 1;
        for (int i = 1; i < m; i++)
            grid[0][i] = grid[0][i - 1] + n;
        for (int i = 1; i < n; i++)
            for (int j = 0; j < m; j++)
                grid[i][j] = grid[i - 1][j] + 1;
    }
    else if (!(m & 1)) {
        grid[0][0] = 1;
        for (int i = 1; i < n; i++)
            grid[i][0] = grid[i - 1][0] + m;
        for (int i = 0; i < n; i++)
            for (int j = 1; j < m; j++)
                grid[i][j] = grid[i][j - 1] + 1;
    }
    else {
        int x = 1;
        for (int i = 0; i < (n + 1) / 2; i++, x += m)
            for (int j = 0; j < m; j++)
                grid[i][j] = x++;
        x = m + 1;
        for (int i = (n + 1) / 2; i < n; i++, x += m)
            for (int j = 0; j < m; j++)
                grid[i][j] = x++;
    }
    out(grid);
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}