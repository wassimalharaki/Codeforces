#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

v<int> check(v<int> a, v<int> b) {
    int n = a.size();

    int up_down = 0, down_up = 0;
    v<int> diff_ud(n + 1), diff_du(n + 1);
    for (int i = 0; i < n - 1; i++) {
        up_down += diff_ud[i];
        down_up += diff_du[i];
        if (a[i] > b[i]) {
            int x = a[i] - b[i];
            int sub = min(down_up, x);
            a[i] -= x, a[i + 1] += x;
            diff_ud[i + 2] += x - sub;
            down_up -= sub;
        }
        else if (a[i] < b[i]) {
            int x = b[i] - a[i];
            int sub = min(up_down, x);
            a[i] += x, a[i + 1] -= x;
            diff_du[i + 2] += x - sub;
            up_down -= sub;
        }
    }
    up_down += diff_ud[n - 1] + diff_ud[n];
    down_up += diff_du[n - 1] + diff_du[n];
    return a == b and up_down == down_up ? a : v<int>();
}

void solve() {
    int n, m; cin >> n >> m;

    v a(n, v<int>(m));
    for (auto& x : a)
        for (auto& y : x)
            cin >> y;
    
    v<int> b;
    v<v<int>> c{a[0], a[1], a[2]};
    sort(c.begin(), c.end());
    do {
        auto d = check(c[0], c[1]);
        if (d.size()) { b = d; break; }
    } while (next_permutation(c.begin(), c.end()));

    int k = -1;
    for (int i = 0; i < n; i++)
        if (check(b, a[i]).empty())
            k = i;

    int ans = 0, x = 0, y = 0;
    for (int j = 0; j < m; j++) {
        x += a[!k][j], y += a[k][j];
        ans += x - y;
    }
    cout << k + 1 << " " << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}