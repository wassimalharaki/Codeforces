#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, q; cin >> n >> q;

    v<int> c(n);
    for (int& x : c) cin >> x;

    v<v<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    v<int> p(n);
    auto dfs = [&](int u, int pp, auto&& dfs) -> void {
        p[u] = pp;
        for (int& i : adj[u])
            if (i != pp)
                dfs(i, u, dfs);
    };
    dfs(0, -1, dfs);

    v<int> cnt_black(n);
    set<int> twos;
    int one_black = 0, two_black = 0, x_black = 0, white_p = 0;

    auto off = [&](int u) {
        white_p += cnt_black[u];
        if (u == 0) white_p--;
        else white_p -= c[p[u]] == 0;

        if (u) {
            if (c[p[u]]) {
                if (cnt_black[p[u]] == 3) {
                    x_black--, two_black++;
                    twos.insert(p[u]);
                }
                else if (cnt_black[p[u]] == 2) {
                    two_black--, one_black++;
                    twos.erase(p[u]);
                }
                else if (cnt_black[p[u]] == 1)
                    one_black--;
            }
            cnt_black[p[u]]--;
        }

        if (cnt_black[u] > 2)
            x_black--;
        else if (cnt_black[u] == 2) {
            two_black--;
            twos.erase(u);
        }
        else if (cnt_black[u] == 1)
            one_black--;
        
        c[u] = !c[u];
    };

    auto on = [&](int u) {
        white_p -= cnt_black[u];
        if (u == 0) white_p++;
        else white_p += c[p[u]] == 0;

        if (u) {
            if (c[p[u]]) {
                if (cnt_black[p[u]] == 2) {
                    two_black--, x_black++;
                    twos.erase(p[u]);
                }
                else if (cnt_black[p[u]] == 1) {
                    one_black--, two_black++;
                    twos.insert(p[u]);
                }
                else if (cnt_black[p[u]] == 0)
                    one_black++;
            }
            cnt_black[p[u]]++;
        }

        if (cnt_black[u] > 2)
            x_black++;
        else if (cnt_black[u] == 2) {
            twos.insert(u);
            two_black++;
        }
        else if (cnt_black[u] == 1)
            one_black++;
        
        c[u] = !c[u];
    };

    auto good = [&]() {
        bool ok = white_p == 1 and x_black == 0 and two_black <= 1;
        if (two_black == 1) {
            int u = *twos.begin();
            ok &= (u == 0 or c[p[u]] == 0);
        }
        return ok;
    };

    for (int i = 1; i < n; i++)
        if (c[i])
            cnt_black[p[i]]++;

    for (int i = 0; i < n; i++) {
        if (c[i] and (i == 0 or c[p[i]] == 0))
            white_p++;
        if (cnt_black[i] > 2)
            x_black++;
        else if (cnt_black[i] == 2) {
            twos.insert(i);
            two_black++;
        }
        else if (cnt_black[i] == 1)
            one_black++;
    }

    while (q--) {
        int u; cin >> u; u--;
        c[u] ? off(u) : on(u);
        cout << (good() ? "Yes" : "No") << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}