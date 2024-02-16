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

int binpow(int a, int b, const int m = 1e9 + 7) {
    a %= m;
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve() {
    int h, w; cin >> h >> w;

    vi r(h), c(w);
    for (int& a : r) cin >> a;
    for (int& a : c) cin >> a;

    vvi grid(h, vi(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < r[i]; j++)
            grid[i][j] = 1;
        if (r[i] < w)
            grid[i][r[i]] = -1;
    }
    
    for (int j = 0; j < w; j++) {
        for (int i = 0; i < c[j]; i++)
            grid[i][j] = 1;
        if (c[j] < h)
            grid[c[j]][j] = -1;
    }
    
    int cnt = 0, ans = 1;
    for (int i = 0; i < h; i++) {
        int check = 0;
        for (int j = 0; j < w; j++)
            if (grid[i][j] == 0)
                cnt++;
        for (int j = 0; j < w; j++)
            if (grid[i][j] == 1)
                check++;
            else
                break;
        if (check != r[i])
            ans = 0;
    }

    for (int j = 0; j < w; j++) {
        int check = 0;
        for (int i = 0; i < h; i++)
            if (grid[i][j] == 1)
                check++;
            else
                break;
        if (check != c[j])
            ans = 0;
    }
    cout << ans * binpow(2, cnt) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}