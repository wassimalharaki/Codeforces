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
    int n, m; cin >> n >> m;

    int nums[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> nums[i][j];
    
    map<int, map<int, int>> map;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int a = i + j, b = n + m - i - j - 2;
            if (a == b) continue;
            int add = min(i + j, n + m - i - j - 2);
            map[add][nums[i][j]]++;
        }
    
    int ans = 0;
    for (auto& [key, cnts] : map) {
        int sum = 0, max = 0;
        for (auto& [key, val] : cnts)
            sum += val, max = std::max(max, val);
        ans += sum - max;
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}