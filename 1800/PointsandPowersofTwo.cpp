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
    sort(a.begin(), a.end());

    auto find = [&](int x) -> bool {
        return binary_search(a.begin(), a.end(), x);
    };

    v<int> ans{a[0]};
    for (int i = 0; i < n; i++)
        for (int j = 1; j < (1ll << 32); j <<= 1)
            if (find(a[i] + j)) {
                if (ans.size() == 1)
                    ans = {a[i], a[i] + j};
                if (ans.size() == 2 and find(a[i] + (j << 1)))
                    ans = {a[i], a[i] + j, a[i] + (j << 1)};
            }

    cout << ans.size() << nl;
    for (int& x : ans)
        cout << x << " ";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}