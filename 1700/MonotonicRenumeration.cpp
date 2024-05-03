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

const int mod = 998244353;

void solve() {
    int n; cin >> n;
 
    map<int, v<int>> indices;
    v<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        indices[nums[i]].push_back(i);
    }
 
    v<int> open(n), close(n);
    for (auto& [key, val] : indices) {
        open[val.front()]++;
        close[val.back()]++;
    }
 
    int ans = 1;
    int current = open[0];
    for (int i = 1; i < n; i++) {
        current += -close[i - 1];
        if (current == 0) ans = ans * 2 % mod;
        current += open[i];
    }
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}