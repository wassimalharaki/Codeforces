#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

v<int> dx{-1, 0, 1, 0};
v<int> dy{0, -1, 0, 1};

void solve() {
    int n, m; cin >> n >> m;

    v a(n, v<int>(m));
    for (auto& x : a) {
        string s; cin >> s;
        for (int i = 0; i < m; i++)
            x[i] = s[i] == '.';
    }
    array<int, 2> src, dst;
    cin >> src[0] >> src[1];
    cin >> dst[0] >> dst[1];
    src[0]--, src[1]--, dst[0]--, dst[1]--;

    auto valid = [&](int i, int j) {
        return i >= 0 and j >= 0 and i < n and j < m and a[i][j];
    };

    if (src == dst) {
        int cnt = 0;
        for (int k = 0; k < 4; k++)
            cnt += valid(src[0] + dx[k], src[1] + dy[k]);
        cout << (cnt ? "YES" : "NO") << nl;
        return;
    }

    v vis(n, v<int>(m));
    auto dfs = [&](int i, int j, auto&& dfs) -> void {
        if (array{i, j} == dst) vis[i][j] = 1;
        if (not valid(i, j) or vis[i][j]) return;
        vis[i][j] = 1;
        for (int k = 0; k < 4; k++)
            dfs(i + dx[k], j + dy[k], dfs);
    };
    a[src[0]][src[1]] = 1;
    dfs(src[0], src[1], dfs);

    int cnt = 4;
    if (a[dst[0]][dst[1]]) {
        cnt = 0;
        for (int k = 0; k < 4; k++)
            cnt += valid(dst[0] + dx[k], dst[1] + dy[k]);
    }
    cout << (vis[dst[0]][dst[1]] and cnt >= 2 ? "YES" : "NO") << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}