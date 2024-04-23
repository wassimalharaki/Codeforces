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
    int n, k, d; cin >> n >> k >> d;

    v<int> a(n), b(k), c(n), per(n), end(n);
    for (int i = 0; i < n; i++)
        cin >> a[i], c[i] = a[i];
    for (int& x : b) {
        cin >> x;
        for (int i = 0; i < x; i++)
            per[i]++;
    }

    auto get = [&](int x) {
        for (int i = 0; i < n; i++)
            c[i] += per[i] * (x / k);

        x %= k;
        for (int i = 0; i < x; i++)
            end[b[i] - 1]++;
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += (c[i] + x) == (i + 1);
            
            x -= end[i];
            c[i] = a[i];
            end[i] = 0;
        }
        return ans;
    };

    int ans = get(0) + (d - 1) / 2;
    for (int i = 0; i < n; i++) {
        if (a[i] >= i + 1) continue;
        if (per[i] == 0) continue;

        int need = i + 1 - a[i];
        int x = (need - 1) / per[i];
        need -= x * per[i];
        x *= k;
        for (int j = 0; j < k and need; j++) {
            x++;
            need -= b[j] > i;
        }
        if (x >= d) continue;
        ans = max(ans, get(x) + (d - x - 1) / 2);
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