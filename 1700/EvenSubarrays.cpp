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

void solve() {
    int n; cin >> n;

    v<int> a(n);
    for (int& x : a) cin >> x;

    v<int> prefix(n + 1);
    for (int i = 0; i < n ; i++)
        prefix[i + 1] = prefix[i] ^ a[i];

    int ans = 0;
    int m = bit_ceil((unsigned int) n + 1);
    v<int> cnt(m + 1);
    cnt[0] = 1;
    for (int i = 0; i < n; i++) {
        int add = i + 1;
        for (int x = 0; x * x < m; x++) {
            int y = (x * x) ^ prefix[i + 1];
            add -= cnt[y];
        }
        ans += add;
        cnt[prefix[i + 1]]++;
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