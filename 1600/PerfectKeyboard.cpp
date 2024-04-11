#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector
#define all(v) v.begin(), v.end()

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

bool check(string& key, string& s) {
    int curr = find(all(key), s[0]) - key.begin(), n = s.size();
    for (int i = 1; i < n; i++) {
        if (curr == 0) {
            if (s[i] != key[++curr])
                return 0;
        }
        else if (curr == key.size() - 1) {
            if (s[i] != key[--curr])
                return 0;
        }
        else {
            if (s[i] == key[curr + 1])
                curr++;
            else if (s[i] == key[curr - 1])
                curr--;
            else
                return 0;
        }
    }
    return 1;
}

void solve() {
    string s; cin >> s;
    int n = s.size();

    v<int> nums(n);
    for (int i = 0; i < n; i++)
        nums[i] = s[i] - 'a';

    v<v<int>> adj(26, v<int>(26));
    v<bool> vis(26);
    for (int i = 0; i < n - 1; i++)
        adj[nums[i]][nums[i + 1]] = 1;
    vis[nums[0]] = 1;

    string left, right;
    auto dfs = [&](int u, string& t, auto&& dfs) -> void {
        t.push_back(u + 'a');
        vis[u] = 1;
        for (int i = 0; i < 26; i++)
            if (adj[u][i] and not vis[i])
                dfs(i, t, dfs);
    };

    bool ok = 0;
    for (int i = 0; i < 26; i++) {
        if (not adj[nums[0]][i]) continue;
        if (ok) {
            if (not vis[i])
                dfs(i, left, dfs);
            break;
        }
        else {
            ok = 1;
            dfs(i, right, dfs);
        }
    }
    reverse(all(left));

    string ans = left + s[0] + right;
    for (int c = 0; c < 26; c++)
        if (not vis[c])
            ans += char('a' + c);

    if (check(ans, s))
        cout << "YES\n" << ans << nl;
    else
        cout << "NO" << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}