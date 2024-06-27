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
    string s = "sjfnb", t = "cslnb";

    map<int, int> cnt;
    v<int> a(n);
    for (int& x : a)
        cin >> x, cnt[x]++;
    sort(a.begin(), a.end());

    int ge2 = 0;
    for (auto& [l, r] : cnt)
        if (r >= 2 and (r >= 3 or l == 0 or ge2++ or cnt.count(l - 1))) {
            cout << t << nl;
            return;
        }
    
    int x = 0;
    for (int i = 0; i < n; i++)
        x += a[i] - i;
    cout << (x & 1 ? s : t) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}