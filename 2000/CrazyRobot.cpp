#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

v<int> dx{-1, 0, 1, 0};
v<int> dy{0, 1, 0, -1};

void solve() {
    int n, m; cin >> n >> m;
    array<int, 2> lab;

    v a(n, v<int>(m));
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++)
            if (s[j] == '#')
                a[i][j] = 0;
            else if (s[j] == '.')
                a[i][j] = 1;
            else
                a[i][j] = 2, lab = {i, j};
    }

    auto valid = [&](int i, int j) {
        return i >= 0 and j >= 0
            and i < n and j < m and a[i][j];
    };

    auto get = [&](int i, int j) -> v<array<int, 2>> {
        v<array<int, 2>> adj;
        for (int k = 0; k < 4; k++) {
            int r = i + dx[k], c = j + dy[k];
            if (valid(r, c))
                adj.push_back({r, c});
        }
        return adj;
    };

    v ans(n, v<int>(m)); ans[lab[0]][lab[1]] = 1;
    auto cnt = [&](int i, int j) -> int {
        int x = 0, y = get(i, j).size();
        for (auto& [r, c] : get(i, j))
            x += ans[r][c];
        return y - x;
    };

    queue<array<int, 2>> q;
    q.push(lab);

    while (q.size()) {
        auto [i, j] = q.front();
        q.pop();

        for (auto& [r, c] : get(i, j))
            if (not ans[r][c] and cnt(r, c) <= 1) {
                ans[r][c] = 1;
                q.push({r, c});
            }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            if (a[i][j] == 0)
                cout << '#';
            else if (a[i][j] == 1)
                cout << (ans[i][j] ? '+' : '.');
            else
                cout << 'L';
        cout << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}