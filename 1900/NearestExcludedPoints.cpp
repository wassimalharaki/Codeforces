#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

v<int> dx{0, -1, 0, 1};
v<int> dy{1, 0, -1, 0};

void solve() {
    int n; cin >> n;

    v<array<int, 3>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
        a[i][2] = i;
    }
    sort(a.begin(), a.end());

    auto find = [&](int x, int y) -> int {
        auto it = lower_bound(a.begin(), a.end(), array<int, 3>{x, y, 0ll});
        if (it == a.end() or (*it)[0] != x or (*it)[1] != y)
            return -1;
        return (*it)[2];
    };
    
    queue<array<int, 3>> q;
    v<int> vis(n);
    v<v<array<int, 2>>> ans(n);
    for (auto& [x, y, i] : a) {
        ans[i].push_back({INT_MAX, INT_MAX});
        bool ok = 0;
        for (int j = 0; j < 4; j++)
            ok |= find(x + dx[j], y + dy[j]) == -1;
        if (ok) {
            q.push({x, y, i});
            vis[i] = 1;
        }
    }

    auto get = [&](int x, int y, int i) -> int {
        return abs(ans[i][0][0] - x) + abs(ans[i][0][1] - y);
    };

    while (q.size()) {
        auto [x, y, i] = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            int j = find(nx, ny);
            if (j == -1) {
                int d = abs(nx - x) + abs(ny - y);
                if (d < get(x, y, i))
                    ans[i] = {{nx, ny}};
                else if (d == get(x, y, i) and ans[i].size() < 10)
                    ans[i].push_back({nx, ny});
            }
            else {
                for (auto& [hx, hy] : ans[j]) {
                    int d = abs(hx - x) + abs(hy - y);
                    if (d < get(x, y, i))
                        ans[i] = {{hx, hy}};
                    else if (d == get(x, y, i) and ans[i].size() < 10)
                        ans[i].push_back({hx, hy});
                }
            }
        }

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            int j = find(nx, ny);
            if (j != -1 and not vis[j]) {
                q.push({nx, ny, j});
                vis[j] = 1;
            }
        }
    }

    for (auto& x : ans)
        cout << x[0][0] << " " << x[0][1] << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}