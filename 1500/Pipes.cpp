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
    int n; cin >> n;
    int nums[2][n + 2];
    nums[0][0] = 1;
    memset(nums, 0, sizeof(nums));
    for (int i = 0; i < 2; i++)
        for (int j = 1; j <= n; j++) {
            char c; cin >> c;
            nums[i][j] = c - '0';
        }
    
    int r = 0, c = 0;
    bool ok = 0;
    while (c < n + 2) {
        if (r == 0) {
            if (ok or nums[r][c] <= 2) {
                c++; ok = 0;
            }
            else {
                if (nums[++r][c] <= 2) {
                    cout << "NO" << nl;
                    return;
                }
                ok = 1;
            }
        }
        else {
            if (ok or nums[r][c] <= 2) {
                c++; ok = 0;
            }
            else {
                if (nums[--r][c] <= 2) {
                    cout << "NO" << nl;
                    return;
                }
                ok = 1;
            }
        }
    }
    cout << (r == 1 ? "YES" : "NO") << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}