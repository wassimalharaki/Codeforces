#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

template<int N, char id>
struct suffix_automaton {
    struct node {
        int sz = 0, link = -1, cnt = 0;
        array<int, N> go;
        node() { go.fill(-1); }
    };
    vector<node> d;
    int last = 0;

    int add_node() {
        d.push_back(node());
        return d.size() - 1;
    }

    suffix_automaton() { add_node(); }

    suffix_automaton(const string& s) {
        add_node();
        for (const char& c : s)
            extend(c);
    }

    void extend(char c) {
        int curr = add_node();
        d[curr].cnt = 1;
        d[curr].sz = d[last].sz + 1;

        int p = last;
        while (p != -1 and d[p].go[c - id] == -1) {
            d[p].go[c - id] = curr;
            p = d[p].link;
        }

        if (p == -1)
            d[curr].link = 0;
        else {
            int q = d[p].go[c - id];
            if (d[p].sz + 1 == d[q].sz)
                d[curr].link = q;
            else {
                int clone = add_node();
                d[clone].sz = d[p].sz + 1;
                d[clone].go = d[q].go;
                d[clone].link = d[q].link;
                while (p != -1 and d[p].go[c - id] == q) {
                    d[p].go[c - id] = clone;
                    p = d[p].link;
                }
                d[q].link = d[curr].link = clone;
            }
        }
        last = curr;
    }
};

void solve() {
    string s; cin >> s;
    int k; cin >> k;
    int n = s.size();
    suffix_automaton<26, 'a'> sa(s);
    int m = sa.d.size();

    v<v<int>> sz(n + 1);
    for (int i = 0; i < (int) sa.d.size(); i++)
        sz[n - sa.d[i].sz].push_back(i);

    for (auto& x : sz)
        for (int& i : x)
            if (sa.d[i].link != -1)
                sa.d[sa.d[i].link].cnt += sa.d[i].cnt;
    sa.d[0].cnt = 1;

    v<int> dp(m);
    auto fill = [&](int u, auto&& fill) -> int {
        if (dp[u]) return dp[u];
        for (int i = 0; i < 26; i++)
            if (sa.d[u].go[i] != -1)
                dp[u] += fill(sa.d[u].go[i], fill);
        return dp[u] += sa.d[u].cnt;
    };
    fill(0, fill);

    string ans;
    auto dfs = [&](int u, auto&& dfs) -> void {
        if (k < sa.d[u].cnt)
            return;
        k -= sa.d[u].cnt;

        for (int i = 0; i < 26; i++) {
            int j = sa.d[u].go[i];
            if (j == -1) continue;
            if (dp[j] <= k)
                k -= dp[j];
            else {
                ans += char('a' + i);
                return dfs(j, dfs);
            }
        }
    };
    dfs(0, dfs);
    if (ans.empty())
        cout << "No such line.";
    else
        cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}