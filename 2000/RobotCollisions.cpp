#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, m; cin >> n >> m;

    set<array<int, 2>> a[2][2];
    {
        v<int> b(n);
        for (int& x : b) cin >> x;
        for (int i = 0; i < n; i++) {
            char c; cin >> c;
            a[b[i] & 1][c == 'R'].insert({b[i], i});
        }
    }

    v<int> ans(n, -1);
    for (int p = 0; p < 2; p++) {
        v<array<int, 2>> kill;
        for (auto [x, i] : a[p][0]) {
            auto it = a[p][1].lower_bound({x, -1});
            if (it == a[p][1].begin()) continue;

            auto [y, j] = *(--it);
            ans[i] = ans[j] = (x - y) / 2;
            kill.push_back({x, i});
            a[p][1].erase(it);
        }
        for (auto& [x, i] : kill)
            a[p][0].erase({x, i});

        v<array<int, 2>> b(a[p][0].begin(), a[p][0].end());
        for (int k = 0; k < (int) b.size() - 1; k += 2) {
            auto [x, i] = b[k];
            auto [y, j] = b[k + 1];
            ans[i] = ans[j] = x + (y - x) / 2;
        }

        v<array<int, 2>> c(a[p][1].begin(), a[p][1].end());
        for (int k = (int) c.size() - 2; k >= 0; k -= 2) {
            auto [x, i] = c[k];
            auto [y, j] = c[k + 1];
            ans[i] = ans[j] = m - y + (y - x) / 2;
        }

        if ((b.size() & 1) and (c.size() & 1)) {
            auto [x, i] = b.back();
            auto [y, j] = c.front();
            if (x > m - y)
                ans[i] = ans[j] = x + (2 * m - x - y) / 2;
            else
                ans[i] = ans[j] = m - y + (y + x) / 2;
        }
    }

    for (int& x : ans)
        cout << x << " ";
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}