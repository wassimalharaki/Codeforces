#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, m; cin >> n >> m;
    int x, k, y; cin >> x >> k >> y;

    v<int> a(n), b(m);
    for (int& z : a) cin >> z;
    for (int& z : b) cin >> z;

    {
        int j = 0;
        for (int i = 0; i < n and j < m; i++)
            if (a[i] == b[j])
                j++;
        if (j != m) {
            cout << -1 << nl;
            return;
        }
    }

    v<v<int>> c{{a[0]}};
    {
        int j = 0;
        for (int i = 0; i < n; i++) {
            c.back().push_back(a[i]);
            if (j < m and a[i] == b[j])
                c.push_back({b[j++]});
        }
        c.back().push_back(b.back());
    }

    int ans = 0;
    for (auto& q : c) {
        int sz = q.size() - 2;
        int mx = *max_element(q.begin(), q.end());

        if (mx > q.front() and mx > q.back() and sz < k) {
            cout << -1 << nl;
            return;
        }

        if (!(mx == q.front() or mx == q.back()))
            sz -= k, ans += x;
        ans += sz % k * y + min(sz / k * x, sz / k * k * y);
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}