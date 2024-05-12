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
    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();

    v<int> a(n);
    for (int& x : a) cin >> x;

    auto check = [&](int k) -> bool {
        v<char> dead(n);
        for (int i = 0; i < k; i++)
            dead[a[i] - 1] = 1;

        int i = 0, j = 0;
        while (i < n and j < m)
            if (s[i] == t[j] and not dead[i])
                i++, j++;
            else
                i++;
        return j == m;
    };

    int lo = 0, hi = n, ans = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        if (check(mid))
            lo = mid + 1, ans = mid;
        else
            hi = mid - 1;
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