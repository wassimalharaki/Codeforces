#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

// O(log(n))
template <int N>
struct binary_trie {
    struct node {
        array<int, 2> c;
        int cnt = 0;
        node() { c.fill(-1); }
    };
    vector<node> d;
    
    int add_node() {
        d.push_back(node());
        return d.size() - 1;
    }
 
    binary_trie() { add_node(); }
 
    void insert(int x) {
        int rt = 0;
        for (int i = N; i >= 0; i--) {
            bool b = (1ll << i) & x;
            if (d[rt].c[b] == -1)
                d[rt].c[b] = add_node();
            rt = d[rt].c[b];
            d[rt].cnt++;
        }
    }

    void erase(int x) {
        int rt = 0;
        for (int i = N; i >= 0; i--) {
            bool b = (1ll << i) & x;
            rt = d[rt].c[b];
            d[rt].cnt--;
        }
    }
 
    int min_xor(int x) {
        int rt = 0, ans = 0;
        for (int i = N; i >= 0; i--) {
            bool b = (1ll << i) & x;
            if (d[rt].c[b] != -1 and d[d[rt].c[b]].cnt)
                rt = d[rt].c[b];
            else
                ans += 1ll << i, rt = d[rt].c[!b];
        }
        return ans;
    }

    int max_xor(int x) {
        int rt = 0, ans = 0;
        for (int i = N; i >= 0; i--) {
            bool b = !((1ll << i) & x);
            if (d[rt].c[b] != -1 and d[d[rt].c[b]].cnt)
                ans += 1ll << i, rt = d[rt].c[b];
            else
                rt = d[rt].c[!b];
        }
        return ans;
    }

    int prod(int x, int k) {
        int rt = 0, ans = 0;
        for (int i = N; i >= 0; i--) {
            if (rt == -1) break;

            bool a = x & (1ll << i);
            bool b = k & (1ll << i);

            if (a and not b) {
                if (d[rt].c[0] != -1)
                    ans += d[d[rt].c[0]].cnt;
                rt = d[rt].c[1];
            }
            else if (not a and not b) {
                if (d[rt].c[1] != -1)
                    ans += d[d[rt].c[1]].cnt;
                rt = d[rt].c[0];
            }
            else if (not a and b)
                rt = d[rt].c[1];
            else
                rt = d[rt].c[0];
        }
        if (rt != -1) ans += d[rt].cnt;
        return ans;
    }
};

void solve() {
    int n, k; cin >> n >> k;

    v<int> a(n);
    for (int& x : a) cin >> x;
    
    binary_trie<30> bit;
    bit.insert(0);
    int64_t curr = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        ans += bit.prod(curr ^= a[i], k);
        bit.insert(curr);
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}