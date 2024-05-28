#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n; cin >> n;

    multiset<int> a;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a.insert(x);
    }

    auto check = [&](int x) -> bool {
        auto it = a.find(x);
        if (it != a.end()) a.erase(it);
        return it != a.end();
    };

    bool ok = 1;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        bool found = 0;
        for (int j = 0; j < 30 and not found and (x >> j) > 0 and ok; j++)
            for (int k = 0; k < 30 and not found and ((x >> j) << k) <= 1e9; k++)
                if (check(((x >> j) << k)))
                    found = 1;
        if (not found) ok = 0;
    }
    cout << (ok ? "YES": "NO") << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}