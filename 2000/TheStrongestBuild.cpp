#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

const int N = 10;
using aiN = array<int, N>;

void solve() {
    int n; cin >> n;

    v a(n, v<int>());
    for (auto& x : a) {
        int m; cin >> m;
        x.resize(m);
        for (int& y : x)
            cin >> y;
    }

    int m; cin >> m;
    set<aiN> bad;
    for (int i = 0; i < m; i++) {
        aiN x; x.fill(0);
        for (int j = 0; j < n; j++)
            cin >> x[j], x[j]--;
        bad.insert(x);
    }

    set<aiN> vis;
    priority_queue<pair<int, aiN>> pq;
    {
        int sum = 0;
        aiN x; x.fill(0);
        for (int i = 0; i < n; i++) {
            x[i] = a[i].size() - 1;
            sum += a[i][x[i]];
        }
        pq.push({sum, x});
    }

    while (pq.size()) {
        auto [d, x] = pq.top();
        pq.pop();

        if (not bad.count(x)) {
            for (int i = 0; i < n; i++)
                cout << x[i] + 1 << " ";
            cout << nl;
            return;
        }

        for (int i = 0; i < n; i++) {
            if (not x[i]) continue;
            d -= a[i][x[i]] - a[i][x[i] - 1], x[i]--;
            if (not vis.count(x)) {
                vis.insert(x);
                pq.push({d, x});
            }
            x[i]++, d += a[i][x[i]] - a[i][x[i] - 1];
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}