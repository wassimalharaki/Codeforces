#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, m, k; cin >> n >> m >> k;

    v a(n, v<int>(m));
    for (auto& x : a) {
        string s; cin >> s;
        for (int i = 0; i < m; i++)
            x[i] = s[i] == '.';
    }

    //l r u d
    v b(n, v(m, array<int, 4>()));
    for (int i = 0; i < n; i++) {
        int l = 0, r = m - 1;
        for (int j = 0; j < m; j++) {
            if (not a[i][j]) l = j;
            l = max(l, j - k);
            b[i][j][0] = l;
        }
        for (int j = m - 1; j >= 0; j--) {
            if (not a[i][j]) r = j;
            r = min(r, j + k);
            b[i][j][1] = r;
        }
    }
    for (int j = 0; j < m; j++) {
        int u = 0, d = n - 1;
        for (int i = 0; i < n; i++) {
            if (not a[i][j]) u = i;
            u = max(u, i - k);
            b[i][j][2] = u;
        }
        for (int i = n - 1; i >= 0; i--) {
            if (not a[i][j]) d = i;
            d = min(d, i + k);
            b[i][j][3] = d;
        }
    }

    array<int, 2> src, dst;
    cin >> src[0] >> src[1] >> dst[0] >> dst[1];
    src[0]--, src[1]--, dst[0]--, dst[1]--;

    v d(n, v<int>(m, INT_MAX));
    queue<array<int, 2>> q;
    v<set<int>> row(n), col(m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j])
                row[i].insert(j), col[j].insert(i);

    q.push({src[0], src[1]});
    d[src[0]][src[1]] = 0;
    row[src[0]].erase(src[1]);
    col[src[1]].erase(src[0]);

    while (q.size()) {
        auto [i, j] = q.front();
        q.pop();

        v<array<int, 2>> kill;
        {
            auto it = row[i].lower_bound(b[i][j][0]);
            while (it != row[i].end() and *it <= b[i][j][1]) {
                kill.push_back({i, *it});
                q.push({i, *it});
                d[i][*it] = d[i][j] + 1;
                it++;
            }
        }
        {
            auto it = col[j].lower_bound(b[i][j][2]);
            while (it != col[j].end() and *it <= b[i][j][3]) {
                kill.push_back({*it, j});
                q.push({*it, j});
                d[*it][j] = d[i][j] + 1;
                it++;
            }
        }
        for (auto& [r, c] : kill)
            row[r].erase(c), col[c].erase(r);
    }

    int ans = d[dst[0]][dst[1]];
    cout << (ans == INT_MAX ? -1 : ans) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}