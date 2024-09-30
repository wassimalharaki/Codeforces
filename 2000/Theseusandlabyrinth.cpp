#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

map<char, v<int>> id{
    {'+', {1, 1, 1, 1}},
    {'-', {1, 0, 1, 0}},
    {'|', {0, 1, 0, 1}},
    {'^', {0, 1, 0, 0}},
    {'>', {0, 0, 1, 0}},
    {'<', {1, 0, 0, 0}},
    {'v', {0, 0, 0, 1}},
    {'L', {0, 1, 1, 1}},
    {'R', {1, 1, 0, 1}},
    {'U', {1, 0, 1, 1}},
    {'D', {1, 1, 1, 0}},
    {'*', {0, 0, 0, 0}},
};

#define left 0
#define up 1
#define right 2
#define down 3

v<int> dx{-1, 0, 1, 0};
v<int> dy{0, -1, 0, 1};

void solve() {
    int n, m; cin >> n >> m;

    v<v<v<int>>> a(n, v<v<int>>(m));
    for (auto& x : a)
        for (auto& y : x) {
            char c; cin >> c;
            y = id[c];
        }
    
    array<int, 2> src, dst;
    cin >> src[0] >> src[1];
    cin >> dst[0] >> dst[1];

    auto valid = [&](int i, int j) {
        return i >= 0 and j >= 0 and i < n and j < m;
    };

    auto get = [&](int i, int j) -> v<array<int, 2>> {
        v<array<int, 2>> neigh;
        for (int k = 0; k < 4; k++) {
            int r = i + dx[k], c = j + dy[k];
            if (valid(r, c))
                neigh.push_back({r, c});
        }
        return neigh;
    };

    auto resolve = [&](int x, int rot) {
        return ((x - rot) % 4 + 4) % 4;
    };

    auto move = [&](int i, int j, int r, int c, int rot) -> bool {
        if (c == j + 1)
            return a[i][j][resolve(right, rot)] and a[r][c][resolve(left, rot)];
        if (c == j - 1)
            return a[i][j][resolve(left, rot)] and a[r][c][resolve(right, rot)];
        if (r == i + 1)
            return a[i][j][resolve(down, rot)] and a[r][c][resolve(up, rot)];
        if (r == i - 1)
            return a[i][j][resolve(up, rot)] and a[r][c][resolve(down, rot)];
    };

    v<v<v<int>>> dist(n, v<v<int>>(m, v<int>(4, 1e9)));
    using ai3 = array<int, 3>;
    queue<ai3> q;
    q.push({src[0] - 1, src[1] - 1, 0});
    dist[src[0] - 1][src[1] - 1][0] = 0;

    while (q.size()) {
        auto [i, j, rot] = q.front();
        int d = dist[i][j][rot];
        q.pop();

        for (auto& [r, c] : get(i, j)) {
            if (not move(i, j, r, c, rot)) continue;
            if (d + 1 < dist[r][c][rot]) {
                dist[r][c][rot] = d + 1;
                q.push({r, c, rot});
            }
        }
        rot = (rot + 1) % 4;
        if (d + 1 < dist[i][j][rot]) {
            dist[i][j][rot] = d + 1;
            q.push({i, j, rot});
        }
    }
    auto& y = dist[dst[0] - 1][dst[1] - 1];
    int x = *min_element(y.begin(), y.end());
    cout << (x == 1e9 ? -1 : x) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}