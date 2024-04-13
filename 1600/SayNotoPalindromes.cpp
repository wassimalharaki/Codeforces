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

v<string> t{
    "abc", "bca", "cab",
    "acb", "cba", "bac",
};

void solve() {
    int n, m; cin >> n >> m;
    string s; cin >> s;

    v<array<int, 6>> nums(n + 1);
    nums[0].fill(0);
    for (int i = 1; i <= n; i++) {
        nums[i] = nums[i - 1];
        for (int j = 0; j < 6; j++)
            nums[i][j] += s[i - 1] != t[j][i % 3];
    }

    while (m--) {
        int l, r; cin >> l >> r;
        array<int, 6> curr;
        for (int i = 0; i < 6; i++)
            curr[i] = nums[r][i] - nums[l - 1][i];
        cout << *min_element(all(curr)) << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}