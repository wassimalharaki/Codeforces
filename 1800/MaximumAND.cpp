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

    v<array<v<int>, 2>> a{{v<int>(n), v<int>(n)}};
    for (int& x : a[0][0]) cin >> x;
    for (int& x : a[0][1]) cin >> x;

    auto valid = [](v<int>& a, v<int>& b, int k) -> bool {
        int cnt_a = 0, cnt_b = 0;
        for (int& x : a)
            if ((1 << k) & x)
                cnt_a++;
        for (int& x : b)
            if (!((1 << k) & x))
                cnt_b++;
        return cnt_a == cnt_b;
    };

    int ans = 0;
    for (int k = 30; k >= 0; k--) {
        bool ok = 1;
        for (auto& [l, r] : a)
            if (not valid(l, r, k))
                ok = 0;
        if (not ok) continue;

        ans |= (1 << k);
        v<array<v<int>, 2>> b;
        for (auto& [l, r] : a) {
            v<int> l_with, l_wout, r_with, r_wout;
            for (int& x : l)
                if ((1 << k) & x)
                    l_with.push_back(x);
                else
                    l_wout.push_back(x);
            for (int& x : r)
                if ((1 << k) & x)
                    r_with.push_back(x);
                else
                    r_wout.push_back(x);
            if (l_with.size())
                b.push_back({l_with, r_wout});
            if (l_wout.size())
                b.push_back({l_wout, r_with});
        }
        a.swap(b);
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