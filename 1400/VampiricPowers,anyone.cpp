#include <bits/stdc++.h>

using namespace std;

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

#define int long long
#define INF LONG_LONG_MAX
#define nl '\n'
#define v vector
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define mp make_pair
#define F first
#define S second

using pii = pair<int, int>;
using vi = v<int>;
using vvi = v<vi>;
using vpii = v<pii>;

void solve() {
    int n; cin >> n;

    vi nums(n);
    for (int& a : nums) cin >> a;

    vi prefix(n);
    partial_sum(all(nums), prefix.begin(), [](int a, int b) {
        return a ^ b;
    });

    v<set<int>> bits(9);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, prefix[i]);
        for (int j = 8; j >= 0; j--) {
            if ((1 << j) & prefix[i]) continue;
            if (bits[j].empty()) continue;
            for (int k : bits[j])
                ans = max(ans, prefix[i] ^ k);
            break;
        }
        if (prefix[i])
            bits[63 - __builtin_clzll(prefix[i])].insert(prefix[i]);
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}