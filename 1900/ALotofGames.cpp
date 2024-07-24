#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

template <int N>
struct trie {
    vector<array<int, N>> d;

    int add_node() {
        array<int, N> x; x.fill(-1);
        d.push_back(x);
        return d.size() - 1;
    }

    trie() { add_node(); }

    void insert(string& s) {
        int rt = 0;
        for (char& c : s) {
            if (d[rt][c - 'a'] == -1)
                d[rt][c - 'a'] = add_node();
            rt = d[rt][c - 'a'];
        }
    }
};

const int N = 26;

void solve() {
    int n, k; cin >> n >> k;

    trie<N> t;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        t.insert(s);
    }

    auto dfs = [&](int u, auto&& dfs) -> array<int, 2> {
        if (count(t.d[u].begin(), t.d[u].end(), -1) == N)
            return array<int, 2>{1, 0};

        array<int, 2> x{0, 0};
        for (int i = 0; i < N; i++)
            if (t.d[u][i] != -1) {
                auto y = dfs(t.d[u][i], dfs);
                if (!y[0]) x[0] = 1;
                if (!y[1]) x[1] = 1;
            }
        return x;
    };
    auto x = dfs(0, dfs);
    
    if (x[0] and x[1])
        cout << "First" << nl;
    else if (x[0])
        cout << "Second" << nl;
    else if (x[1])
        cout << (k & 1 ? "First" : "Second") << nl;
    else
        cout << "Second" << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}