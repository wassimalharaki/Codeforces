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
    
    v<int> nums(m);
    for (int& a : nums) cin >> a;

    int x = *max_element(all(nums)), cnt = count(all(nums), (n + k - 1) / k);
    cout << (x > (n + k - 1) / k or cnt > (n - 1) % k + 1 ? "NO" : "YES") << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}