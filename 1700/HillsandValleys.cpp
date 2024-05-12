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

    int curr = 0;
    for (int i = 1; i < n - 1; i++)
        if (a[i] > a[i - 1] and a[i] > a[i + 1])
            curr++;
        else if (a[i] < a[i - 1] and a[i] < a[i + 1])
            curr++;
    
    auto check = [&](int i) -> bool {
        if (i - 1 < 0 or i + 1 >= n) return 0;
        return (a[i] > a[i - 1] and a[i] > a[i + 1])
            or (a[i] < a[i - 1] and a[i] < a[i + 1]);
    };

    auto get = [&](int i) -> array<int, 3> {
        return {check(i + 1), check(i), check(i - 1)};
    };
        
    int ans = curr;
    for (int i = 0; i < n; i++) {
        auto x = get(i);
        int k = curr - (x[0] + x[1] + x[2]);
        int orig = a[i];

        if (i) {
            a[i] = a[i - 1];
            auto y = get(i);
            k += y[0] + y[1] + y[2];
            ans = min(ans, k);
            k = curr - (x[0] + x[1] + x[2]);
        }

        if (i + 1 < n) {
            a[i] = a[i + 1];
            auto y = get(i);
            k += y[0] + y[1] + y[2];
            ans = min(ans, k);
        }
        a[i] = orig;
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