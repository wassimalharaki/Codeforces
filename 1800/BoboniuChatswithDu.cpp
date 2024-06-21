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
    int n, d, m; cin >> n >> d >> m;

    v<int> a(n);
    for (int& x : a) cin >> x;
    sort(a.begin(), a.end());

    int ans = a.back();
    a.pop_back();
    n--;

    v<int> good, bad;
    int extra = n % (d + 1), cnt = d + 1;
    for (int i = n - 1; i >= 0; i--)
        if (a[i] <= m) {
            if (extra)
                ans += a[i], extra--;
            else {
                if (cnt == d + 1)
                    cnt = 0, good.push_back(0);
                cnt++;
                good.back() += a[i];
            }
        }
        else
            bad.push_back(a[i]);

    int i = 0, j = 0;
    for (int k = 0; k < n / (d + 1); k++) {
        int x = (i < good.size() ? good[i] : 0);
        int y = (j < bad.size() ? bad[j] : 0);
        if (x > y)
            ans += x, i++;
        else
            ans += y, j++;
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