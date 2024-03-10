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

int fact[16];

int popcnt(int n) {
    return __builtin_popcountll(n);
}

void solve() {
    int n; cin >> n;

    int ans = popcnt(n);
    for (int mask = 0; mask < (1 << 16); mask++) {
        int sum = 0;
        for (int i = 0; i < 16; i++)
            if ((1 << i) & mask)
                sum += fact[i];
        
        if (sum <= n)
            ans = min(ans, popcnt(mask) + popcnt(n - sum));
        else break;
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fact[0] = fact[1] = 1;
    for (int i = 2; i < 16; i++)
        fact[i] = fact[i - 1] * i;

    int T = 1;
    cin >> T;
    while (T--) solve();
}