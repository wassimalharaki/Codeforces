#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n; cin >> n;
    int a, b;

    if (n & 1) {
        for (int i = 0; i < n - 1; i++)
            cin >> a >> b;
        cout << a << " " << b << nl << a << " " << b << nl;
        return;
    }

    v<v<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    v<int> cnt(n + 1), p(n + 1);
    auto dfs = [&](int u, int par, auto&& dfs) -> void {
        cnt[u]++;
        p[u] = par;

        for (int& i : adj[u])
            if (i != par) {
                dfs(i, u, dfs);
                cnt[u] += cnt[i];
            }
    };
    dfs(1, 0, dfs);

    for (int u = 1; u <= n; u++)
        for (int& i : adj[u])
            if (p[i] == u) {
                int x = n - cnt[i];
                int y = cnt[i];
                if (x != y) continue;

                int z = i;
                bool ok = 1;
                while (ok) {
                    ok = 0;
                    for (int& j : adj[z])
                        if (j != p[z]) {
                            z = j;
                            ok = 1;
                            break;
                        }
                }
                cout << z << " " << p[z] << nl << z << " " << u << nl;
                return;
            }
            else {
                int x = cnt[u];
                int y = n - cnt[u];
                if (x != y) continue;

                int z = u;
                bool ok = 1;
                while (ok) {
                    ok = 0;
                    for (int& j : adj[z])
                        if (j != p[z]) {
                            z = j;
                            ok = 1;
                            break;
                        }
                }
                cout << z << " " << p[z] << nl << z << " " << i << nl;
                return;
            }
    cout << a << " " << b << nl << a << " " << b << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}