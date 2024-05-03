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

void solve() {
    int n; cin >> n;
    n <<= 1;

    v<int> a(n);
    for (int& x : a) cin >> x;
    sort(a.begin(), a.end());

    for (int i = 0; i < n - 1; i++) {
        v<array<int, 2>> ops{{a[i], a[n - 1]}};

        multiset<int> b(a.begin(), a.end());
        b.erase(b.find(a[n - 1]));
        b.erase(b.find(a[i]));
        bool ok = 1;

        int x = a[n - 1];
        while (ok and b.size()) {
            ok = 0;
            int r = *(--b.end());
            int look = x - r;
            auto it = b.find(look);
            if (it == b.end() or it == --b.end()) break;
            x = r;
            ops.push_back({r, *it});
            b.erase(--b.end());
            b.erase(it);
            ok = 1;
        }
        if (not ok) continue;

        cout << "YES" << nl << a[n - 1] + a[i] << nl;
        for (auto& x : ops)
            cout << x[0] << " " << x[1] << nl;
        return;
    }

    cout << "NO" << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}