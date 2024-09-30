#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

const int mod = 998244353;

// O(log(b))
int binpow(int a, int b, const int m = mod) {
    a %= m;
    int res = 1;
    while (b) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n; cin >> n;

    v<int> a(n), b(n), cnt(n + 1);
    for (int& x : a)
        cin >> x, cnt[x]++;
    for (int& x : b)
        cin >> x, cnt[x]++;

    for (int i = 1; i <= n; i++)
        if (cnt[i] == 0) {
            cout << 0 << nl;
            return;
        }

    v<v<array<int, 2>>> adj(n + 1);
    v<set<int>> ind(n + 1);
    for (int i = 0; i < n; i++) {
        adj[a[i]].push_back({b[i], i});
        adj[b[i]].push_back({a[i], i});
        ind[a[i]].insert(i);
        ind[b[i]].insert(i);
    }

    int ans = 1;
    v<int> vis(n + 1), dead(n);
    auto dfs = [&](int x, int i, auto&& dfs) -> void { 
        if (vis[x]) { ans = 0; return; }
        vis[x] = 1; dead[i] = 1;
        cnt[a[i]]--, cnt[b[i]]--;
        ind[a[i]].erase(i);
        ind[b[i]].erase(i);
        for (auto& [y, j] : adj[x])
            if (not dead[j])
                dfs(y, j, dfs);
        if (cnt[a[i]] == 1 and not vis[a[i]])
            dfs(a[i], *ind[a[i]].begin(), dfs);
        if (cnt[b[i]] == 1 and not vis[b[i]])
            dfs(b[i], *ind[b[i]].begin(), dfs);
    };

    for (int i = 0; i < n; i++)
        if (a[i] == b[i]) {
            ans = ans * n % mod;
            dfs(a[i], i, dfs);
        }
        else if (cnt[a[i]] == 1)
            dfs(a[i], i, dfs);
        else if (cnt[b[i]] == 1)
            dfs(b[i], i, dfs);

    int p = 0;
    for (int i = 0; i < n; i++)
        if (not vis[a[i]] and not vis[b[i]]) {
            p++;
            dfs(a[i], i, dfs);
        }
    
    ans = ans * binpow(2, p) % mod;
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}