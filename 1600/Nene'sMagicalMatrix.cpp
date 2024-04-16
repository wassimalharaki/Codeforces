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
 
    v<array<int, 2>> ops;
    v<v<int>> nums(n, v<int>(n));
    for (int i = 0; i < 2 * n; i++) {
        if (!(i & 1)) {
            ops.push_back({2, i / 2 + 1});
            int x = n;
            for (int j = 0; j < n; j++) {
                nums[j][i / 2] = x--;
            }
        }
        else {
            ops.push_back({1, i / 2 + 1});
            int x = n;
            for (int j = 0; j < n; j++) {
                nums[i / 2][j] = x--;
            }
        }
    }
 
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += accumulate(all(nums[i]), 0ll);
 
    cout << sum << " " << ops.size() << nl;
    for (int i = 0; i < ops.size(); i++) {
        cout << ops[i][0] << " " << ops[i][1] << " ";
        for (int j = n; j >= 1; j--)
            cout << j << " ";
        cout << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}