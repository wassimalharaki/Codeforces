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
    int n, k; cin >> n >> k;

    v<int> a(n);
    for (int& x : a) cin >> x;

    map<int, int> cnt;
    v<int> start(2 * k + 1), end(2 * k + 1);
    for (int i = 0; i < n / 2; i++) {
        int x = max(a[i], a[n - i - 1]);
        int y = min(a[i], a[n - i - 1]);
        cnt[x + y]++;
        start[y + 1]++;
        end[x + k]++;
    }

    v<int> ones(2 * k + 1);
    for (int i = 2; i <= 2 * k; i++)
        ones[i] = ones[i - 1] + start[i] - end[i - 1];

    int ans = 1e9;
    for (int i = 2; i <= 2 * k; i++)
        ans = min(ans, n - ones[i] - cnt[i]);
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}