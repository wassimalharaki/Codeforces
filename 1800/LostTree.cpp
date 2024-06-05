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

int n;

v<int> ask(int u) {
    cout << "? " << u << endl;
    v<int> d(n);
    for (int& x : d) cin >> x;
    return d;
}

void solve() {
    cin >> n;

    set<array<int, 2>> edges;
    set<int> ok;
    v<int> vis(n); vis[0] = 1;
    auto d = ask(1);

    int e = 0, o = 0;
    for (int i = 1; i < n; i++) {
        d[i] & 1 ? o++ : e++;
        if (d[i] == 1)
            edges.insert({1, i + 1});
    }

    if (o < e) {
        for (int i = 1; i < n; i++)
            if (d[i] & 1)
                ok.insert(i);
    }
    else {
        for (int i = 1; i < n; i++)
            if (d[i] & 1 ^ 1)
                ok.insert(i);
    }

    while (edges.size() < n - 1) {
        int u = *ok.begin();
        ok.erase(ok.begin());
        if (vis[u]) continue;
        vis[u] = 1; 
        auto d = ask(u + 1);

        for (int i = 0; i < n; i++)
            if (i == u)
                continue;
            else if (d[i] == 1)
                edges.insert({min(u + 1, i + 1), max(u + 1, i + 1)});
            else if (d[i] & 1 ^ 1)
                ok.insert(i);
    }

    cout << "! " << endl;
    for (auto& [l, r] : edges)
        cout << l << " " << r << endl;
}

signed main() {
    int T = 1;
    // cin >> T;
    while (T--) solve();
}