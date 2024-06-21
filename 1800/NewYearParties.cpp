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

    v<int> a(n);
    for (int& x : a) cin >> x;
    sort(a.begin(), a.end());

    set<int> min, max;
    for (int& x : a) {
        if (not max.count(x - 1))
            max.insert(x - 1);
        else if (not max.count(x))
            max.insert(x);
        else
            max.insert(x + 1);
        
        if (not min.count(x - 1) and not min.count(x))
            min.insert(x + 1);
    }
    cout << min.size() << " " << max.size() << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}