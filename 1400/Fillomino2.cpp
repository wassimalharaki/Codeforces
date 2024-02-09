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
    int n; cin >> n;

    vvi grid(n, vi(n, 0));
    for (int i = 0; i < n; i++)
        cin >> grid[i][i];

    auto is_valid = [&](int r, int c) {
        return r >= 0 and c >= 0 and r < n and c < n;
    };

    for (int i = 0; i < n; i++) {
        int a = grid[i][i];
        int r, c;
        if (i == 0)
            r = i + 1, c = i;
        else {
            if (grid[i][i - 1])
                r = i + 1, c = i;
            else
                r = i, c = i - 1;
        }
        for (int j = 1; j < a; j++) {
            if (not is_valid(r, c)) {
                cout << -1 << nl;
                return;
            }
            grid[r][c] = a;
            if (c and grid[r][c - 1] == 0)
                c--;
            else
                r++;
        }
    }

    for (auto& a : grid) {
        for (auto& b : a)
            if (b)
                cout << b << " ";
        cout << nl;
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