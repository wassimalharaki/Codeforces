#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

const int mod = 998244353;

void solve() {
    int n, m; cin >> n >> m;

    v<int> a(n), b(m);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;

    {
        v<int> c(a);
        sort(c.begin(), c.end());
        c.resize(unique(c.begin(), c.end()) - c.begin());

        auto get = [&](int x) -> int {
            auto it = lower_bound(c.begin(), c.end(), x);
            if (it == c.end() or *it != x) return -1;
            return it - c.begin();
        };

        for (int& x : a) x = get(x);
        for (int& x : b)
            if ((x = get(x)) == -1)
                return void(cout << 0 << nl);
    }
    if (b[0])
        return void(cout << 0 << nl);

    v<int> c(n);
    for (int i = 0; i < n; i++)
        c[a[i]] = i;
    
    v<int> r(m);
    for (int i = 0; i < m - 1; i++)
        r[i] = max(r[i], *max_element(c.begin() + b[i],
            c.begin() + b[i + 1]));

    for (int i = 1; i < m; i++)
        if (c[b[i]] < r[i - 1])
            return void(cout << 0 << nl);

    int ans = 1;
    for (int i = 0; i < m - 1; i++)
        ans = ans * (c[b[i + 1]] - r[i]) % mod;
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}