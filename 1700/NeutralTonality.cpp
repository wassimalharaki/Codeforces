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
    int n, m; cin >> n >> m;

    v<int> a(n);
    for (int& x : a) cin >> x;
    multiset<int> b;
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        b.insert(x);
    }
    set<int> s(a.begin(), a.end());
    s.insert(INT_MAX);

    v<int> ans;
    for (int i= 0; i < n; i++) {
        int x = *s.upper_bound(a[i]);
        v<int> c;
        auto it = b.lower_bound(a[i]);
        while (it != b.end() and *it < x) {
            c.push_back(*it);
            b.erase(it);
            it = b.lower_bound(a[i]);
        }
        reverse(c.begin(), c.end());
        for (int& y : c)
            ans.push_back(y);
        ans.push_back(a[i]);
    }
    for (auto it = b.rbegin(); it != b.rend(); it++)
        ans.push_back(*it);
    
    for (int& x : ans)
        cout << x << " ";
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}