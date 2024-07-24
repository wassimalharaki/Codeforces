#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

template <int N>
struct binary_trie {
    vector<array<int, 2>> d;
    
    int add_node() {
        d.push_back(array<int, 2>{-1, -1});
        return d.size() - 1;
    }

    binary_trie() { add_node(); }

    void add(int x) {
        int rt = 0;
        for (int i = N; i >= 0; i--) {
            bool b = (1 << i) & x;
            if (d[rt][b] == -1)
                d[rt][b] = add_node();
            rt = d[rt][b];
        }
    }

    int max_xor(int x) {
        int rt = 0, ans = 0;
        for (int i = N; i >= 0; i--) {
            bool b = !((1 << i) & x);
            if (d[rt][b] != -1)
                ans += 1 << i, rt = d[rt][b];
            else
                rt = d[rt][!b];
        }
        return ans;
    }
};

void solve() {
    int n; cin >> n;

    v<int> a(n - 1), ans(n);
    for (int& x : a) cin >> x;

    int y = 0;
    binary_trie<20> trie;
    trie.add(y);
    for (int i = 0; i < n - 1; i++)
        y ^= a[i], trie.add(y);
    
    for (int i = 0; i < n; i++)
        if (trie.max_xor(i) < n) {
            ans[0] = i;
            break;
        }

    for (int i = 1; i < n; i++)
        ans[i] = a[i - 1] ^ ans[i - 1];

    for (int& x : ans)
        cout << x << " ";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}