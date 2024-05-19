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
    map<int, int> b;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        b[x]++;
    }

    auto rem = [&](int x) -> void {
        if (--b[x] == 0)
            b.erase(x);
    };

    v<int> ans(n);
    for (int i = 0; i < n; i++) {
        auto it1 = b.lower_bound(n - a[i]);

        if (it1 == b.end()) {
            auto it2 = b.lower_bound(0);

            int x = (a[i] + it2 -> first) % n;
            ans[i] = x;
            rem(it2 -> first);
        }
        else {
            auto it2 = b.lower_bound(0);

            int x = (a[i] + it1 -> first) % n;
            int y = (a[i] + it2 -> first) % n;
            if (x < y) {
                ans[i] = x;
                rem(it1 -> first);
            }
            else {
                ans[i] = y;
                rem(it2 -> first);
            }
        }
    }
    for (int& a : ans)
        cout << a << " ";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}