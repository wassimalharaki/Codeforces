#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

int ask(int a, int b) {
    cout << "? " << a + 1 << " " << b + 1 << endl;
    int c; cin >> c;
    return c - 1;
}

void ans(int c) {
    cout << "! " << c + 1 << endl;
    exit(0);
}

void solve() {
    int n; cin >> n;

    v<set<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].insert(b);
        adj[b].insert(a);
    }

    auto kill = [&](int u, int p, auto&& kill) -> void {
        for (int i : adj[u])
            adj[i].erase(u);
        for (int i : adj[u])
            if (i != p)
                kill(i, u, kill);
        adj[u].clear();
    };

    int a, b, c;
    for (int i = 0; i < n; i++)
        while (adj[i].size() > 1) {
            a = *(adj[i].begin());
            b = *(++adj[i].begin());
            c = ask(a, b);
            if (c == i) {
                kill(a, c, kill);
                kill(b, c, kill);
            }
            else
                kill(i, c, kill);                
        }
    
    v<int> alive;
    for (int i = 0; i < n; i++)
        if (adj[i].size())
            alive.push_back(i);
    
    int m = alive.size();
    for (int i = 0; i < m - (m & 1); i += 2) {
        a = alive[i];
        b = alive[i + 1];
        c = ask(a, b);
        if (c == a or c == b)
            ans(c);
    }
    ans(c);
}

signed main() {
    int T = 1;
    // cin >> T;
    while (T--) solve();
}