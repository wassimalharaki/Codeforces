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

    v<int> nums(n);
    for (int& a : nums) cin >> a;


    v<pair<int, int>> blocks{{nums[0], 1}};
    for (int i = 1; i < n; i++)
        if (nums[i] == blocks.back().first)
            blocks.back().second++;
        else
            blocks.push_back({nums[i], 1});
    
    int ans = 0;
    if (blocks[0].first == 1)
        ans = 1 + (blocks[0].second - 1) / 3;
    for (int i = 1; i < blocks.size(); i++)
        if (blocks[i].first == 1)
            ans += blocks[i].second / 3;
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}