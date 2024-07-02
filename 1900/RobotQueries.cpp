#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n, q; cin >> n >> q;
    string s; cin >> s;
    v<char> dir{'U', 'D', 'R', 'L'};

    v<v<int>> fpfx(n + 1, v<int>(4));
    for (int i = 0; i < n; i++) {
        fpfx[i + 1] = fpfx[i];
        for (int j = 0; j < 4; j++)
            fpfx[i + 1][j] += s[i] == dir[j];
    }

    map<array<int, 2>, array<int, 2>> fpnts{
        {{0, 0}, {-1,-1}}
    };
    for (int i = 0; i < n; i++) {
        int x = fpfx[i + 1][2] - fpfx[i + 1][3];
        int y = fpfx[i + 1][0] - fpfx[i + 1][1];
        if (fpnts.count({x, y}))
            fpnts[{x, y}][1] = i;
        else
            fpnts[{x, y}] = {i, i};
    }

    reverse(s.begin(), s.end());
    v<v<int>> bpfx(n + 1, v<int>(4));
    for (int i = 0; i < n; i++) {
        bpfx[i + 1] = bpfx[i];
        for (int j = 0; j < 4; j++)
            bpfx[i + 1][j] += s[i] == dir[j];
    }

    map<array<int, 2>, v<int>> bpnts{
        {{0, 0}, {-1}}
    };
    for (int i = 0; i < n; i++) {
        int x = bpfx[i + 1][2] - bpfx[i + 1][3];
        int y = bpfx[i + 1][0] - bpfx[i + 1][1];
        bpnts[{x, y}].push_back(i);
    }

    while (q--) {
        int x, y, l, r;
        cin >> x >> y >> l >> r;
        l--, r--;

        if (fpnts.count({x, y})) {
            int first = fpnts[{x, y}][0];
            int last = fpnts[{x, y}][1];
            if (first < l or last > r) {
                cout << "YES" << nl;
                continue;
            }
        }

        int xo = fpfx[l][2] - fpfx[l][3];
        int yo = fpfx[l][0] - fpfx[l][1];

        int xd = x - xo;
        int yd = y - yo;
        xd += fpfx[n][2] - fpfx[r + 1][2]
            - (fpfx[n][3] - fpfx[r + 1][3]);
        yd += fpfx[n][0] - fpfx[r + 1][0]
            - (fpfx[n][1] - fpfx[r + 1][1]);
        
        if (bpnts.count({xd, yd})) {
            auto it = lower_bound(bpnts[{xd, yd}].begin(), bpnts[{xd, yd}].end(), n - r - 1);
            if (it != bpnts[{xd, yd}].end())
                if (*it <= n - l - 1) {
                    cout << "YES" << nl;
                    continue;
                }
        }
        cout << "NO" << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}