#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector
#define all(v) v.begin(), v.end()

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n; cin >> n;

    int lmost, rmost, ans;
    rmost = - (lmost = ans = INT_MAX);
    int lprice, rprice, both;
    lprice = rprice = both = INT_MAX;
    for (int i = 0; i < n; i++) {
        int l, r, c; cin >> l >> r >> c;

        if (l == lmost and r == rmost)
            both = min(both, c);
        if (l == lmost)
            lprice = min(lprice, c);
        if (r == rmost)
            rprice = min(rprice, c);

        if (l < lmost and r > rmost) {
            lmost = l, rmost = r;
            lprice = rprice = both = c;
        }
        else if (l < lmost) {
            lmost = l, lprice = c;
            both = (r == rmost ? c : INT_MAX);
        }
        else if (r > rmost) {
            rmost = r, rprice = c;
            both = (l == lmost ? c : INT_MAX);
        }
        
        cout << min(lprice + rprice, both) << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}