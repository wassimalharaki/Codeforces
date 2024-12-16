#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

const int N = 18;

void solve() {
    int n; cin >> n;

    v<v<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    array<v<int>, 2> a;
    auto dfs = [&](int u, int p, bool b, auto&& self) -> void {
        a[b].push_back(u);
        for (int& i : adj[u])
            if (i != p)
                self(i, u, !b, self);
    };
    dfs(0, -1, 0, dfs);
    if (a[0].size() < a[1].size())
        swap(a[0], a[1]);

    array<v<int>, N> have;
    for (int i = 1; i <= n; i++)
        have[__lg(i)].push_back(i);
    sort(have.begin(), have.end(), [](auto& x, auto& y) {
        return x.size() > y.size();
    });

    v<int> ans(n);
    for (auto& b : a) {
        int j = 0;
        while (b.size()) {
            while (have[j].empty() or have[j].size() > b.size())
                j++;
            ans[b.back()] = have[j].back();
            b.pop_back();
            have[j].pop_back();
        }
    }

    for (int& x : ans)
        cout << x << " ";
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}