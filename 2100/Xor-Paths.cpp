#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, m; cin >> n >> m;

    v a(n, v<int>(m)); cin >> a[0][0];
    for (auto& x : a)
        for (int& y : x) {
            int z; cin >> z;
            y ^= z;
        }

    array<int, 2> sz{
        (n + m - 2) / 2,
        n + m - 2 - (n + m - 2) / 2
    };
    v src(sz[0] + 1, v<v<int>>(sz[0] + 1));
    v dst(sz[1] + 1, v<v<int>>(sz[1] + 1));

    auto valid = [&](int i, int j) {
        return i >= 0 and j >= 0 and i < n and j < m;
    };

    for (int mask = 0; mask < (1 << sz[0]); mask++) {
        int x = a[0][0], i = 0, j = 0;
        for (int k = 0; k < sz[0]; k++)
            if ((1 << k) & mask) {
                if (valid(i, ++j))
                    x ^= a[i][j];
            }
            else {
                if (valid(++i, j))
                    x ^= a[i][j];
            }
        src[i][j].push_back(x);
    }

    for (int mask = 0; mask < (1 << sz[1]); mask++) {
        int x = 0, i = n - 1, j = m - 1;
        for (int k = sz[1] - 1; k >= 0; k--)
            if ((1 << k) & mask) {
                if (valid(i, j))
                    x ^= a[i][j];
                --j;
            }
            else {
                if (valid(i, j))
                    x ^= a[i][j];
                --i;
            }
        dst[n - 1 - i][m - 1 - j].push_back(x);
    }
    for (auto& x : dst)
        for (auto& y : x)
            sort(y.begin(), y.end());
    
    int ans = 0;
    for (int i = 0; i <= sz[0]; i++)
        for (int j = 0; j <= sz[0]; j++)
            if (0 <= n - 1 - i and n - 1 - i <= sz[1] and
                    0 <= m - 1 - j and m - 1 - j <= sz[1])
            for (int& x : src[i][j]) {
                auto& y = dst[n - 1 - i][m - 1 - j];
                ans += upper_bound(y.begin(), y.end(), x)
                    - lower_bound(y.begin(), y.end(), x);
            }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}