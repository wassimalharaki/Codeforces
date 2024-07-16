#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

using ai3 = array<int, 3>;

void solve() {
    int n; cin >> n;

    v<array<int, 2>> a(n);
    for (auto& x : a)
        cin >> x[0] >> x[1];

    v<int> b(n), c(n);
    for (int& x : b) cin >> x;
    for (int& x : c) cin >> x;

    auto get = [&](int i, int j) {
        if (i == j)
            return b[i];
        return (c[i] + c[j])
            * (abs(a[i][0] - a[j][0]) + abs(a[i][1] - a[j][1]));
    };

    priority_queue<ai3, v<ai3>, greater<ai3>> pq;
    for (int i = 0; i < n; i++)
        pq.push({get(i, i), i, i});
    
    int ans = 0;
    v<int> node, dead(n);
    v<array<int, 2>> edge;

    for (int i = 0; i < n; i++) {
        auto [w, x, y] = pq.top();
        while (dead[y]) {
            pq.pop();
            auto [w1, x1, y1] = pq.top();
            w = w1, x = x1, y = y1;
        }

        ans += w;
        if (x == y)
            node.push_back(x);
        else
            edge.push_back({x, y});
        dead[y] = 1;

        for (int j = 0; j < n; j++)
            if (not dead[j])
                pq.push({get(y, j), y, j});
    }

    cout << ans << nl;
    cout << node.size() << nl;
    for (int& x : node)
        cout << x + 1 << " ";
    cout << nl;
    cout << edge.size() << nl;
    for (auto& [x, y] : edge)
        cout << x + 1 << " " << y + 1 << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}