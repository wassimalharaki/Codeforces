#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector
#define all(v) v.begin(), v.end()

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n, m, k; cin >> n >> m >> k;

    v<v<int>> cover(n, v<int>(m)),
              nums(n, v<int>(m));
    for (auto& a : nums)
        for (auto& b : a) {
            char c; cin >> c;
            b = c == '*';
        }
    
    auto valid = [&](int r, int c) {
        return r >= 0 and c >= 0 and r < n and c < m;
    };

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (not nums[i][j]) continue;

            int r = i, c = j;
            int x = -1;
            while (valid(r, c))
                if (not nums[r--][c--])
                    break;
                else x++;

            r = i, c = j;
            int y = -1;
            while (valid(r, c))
                if (not nums[r--][c++])
                    break;
                else y++;
            
            int d = min(x, y);
            if (d < k) continue;

            r = i, c = j;
            for (int l = 0; l <= d; l++)
                cover[r--][c--] = 1;
            r = i, c = j;
            for (int l = 0; l <= d; l++)
                cover[r--][c++] = 1;
        }
    cout << (cover == nums ? "YES" : "NO") << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}