#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, m; cin >> n >> m;

    v<int> a(n);
    map<int, int> cnt;
    {
        for (int& x : a)
            cin >> x, cnt[x]++;
        sort(a.begin(), a.end());
        a.resize(unique(a.begin(), a.end()) - a.begin());
    }
    auto get = [&](int x) -> int {
        return lower_bound(a.begin(), a.end(), x) - a.begin();
    };

    v<pair<int, v<int>>> b;
    {
        map<int, v<int>> rev_cnt;
        for (auto it = cnt.rbegin(); it != cnt.rend(); it++) {
            auto [x, y] = *it;
            rev_cnt[y].push_back(x);
        }

        for (auto& [x, y] : rev_cnt)
            b.push_back({x, y});
    }

    int k = a.size();
    v<v<array<int, 2>>> adj(k);
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        adj[get(x)].push_back({cnt[y], y});
        adj[get(y)].push_back({cnt[x], x});
    }
    for (int& x : a)
        adj[get(x)].push_back({cnt[x], x});

    for (auto& x : adj)
        sort(x.begin(), x.end(), [](auto& l, auto& r) {
            if (l[0] == r[0])
                return l[1] > r[1];
            return l[0] < r[0];
        });
    
    int ans = 0;
    for (int i = 0; i < k; i++) {
        int j = 0, x = a[i], cntx = cnt[x];
        for (auto& [cnty, c] : b) {
            while (j < (int) adj[i].size() and adj[i][j][0] < cnty)
                j++;
            for (int& y : c)
                if (j < (int) adj[i].size() and adj[i][j][1] == y)
                    j++;
                else {
                    ans = max(ans, (x + y) * (cntx + cnty));
                    break;
                }
        }
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