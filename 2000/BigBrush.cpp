#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

v<int> dx{0, 1, 0, 1, -1, -1, -1,  0,  1};
v<int> dy{0, 0, 1, 1, -1,  0,  1, -1, -1};

bool check(v<array<int, 3>>& ans, v<v<int>>& a) {
    v b(a.size(), v<int>(a[0].size()));
    for (auto [i, j, c] : ans)
        for (int k = 0; k < 4; k++)
            b[i - 1 + dx[k]][j - 1 + dy[k]] = c;
    return a == b;
}

void solve() {
    int n, m; cin >> n >> m;

    v a(n, v<int>(m));
    for (auto& x : a)
        for (int& y : x)
            cin >> y;
    auto b = a;

    auto valid = [&](int i, int j) {
        return i >= 0 and j >= 0 and i < n and j < m;
    };

    set<int> ok;
    auto square = [&](int i, int j) -> int {
        ok.clear();
        for (int k = 0; k < 4; k++)
            if (not valid(i + dx[k], j + dy[k]))
                return 0;
            else
                ok.insert(a[i + dx[k]][j + dy[k]]);
        ok.erase(0);
        if (ok.size() != 1) return 0;
        return *ok.begin();
    };

    v<array<int, 3>> ans;
    auto add = [&](int i, int j, int k) {
        ans.push_back({i + 1, j + 1, k});
    };

    queue<array<int, 3>> q;
    v vis(n, v<char>(m));
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < m - 1; j++)
            if (square(i, j)) {
                q.push({i, j, a[i][j]});
                vis[i][j] = 1;
            }

    while (q.size()) {
        auto [i, j, y] = q.front();
        q.pop();

        add(i, j, y);
        for (int k = 0; k < 4; k++)
            a[i + dx[k]][j + dy[k]] = 0;
        for (int k = 0; k < 9; k++) {
            int r = i + dx[k], c = j + dy[k];
            int x = square(r, c);
            if (x and not vis[r][c]) {
                q.push({r, c, x});
                vis[r][c] = 1;
            }
        }
    }
    reverse(ans.begin(), ans.end());

    if (not check(ans, b))
        cout << -1 << nl;
    else {
        cout << ans.size() << nl;
        for (auto& [i, j, k] : ans)
            cout << i << " " << j << " " << k << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}