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
    string s; cin >> s;
 
    int ans = 1;
    for (int k = 2; k <= n; k++) {
        bool ok = 1;
        v<int> ends(n);
        string t = s;
        int curr = 0;
        for (int i = 0; i < n; i++) {
            if (curr & 1)
                t[i] = (t[i] == '1' ? '0' : '1');
            if (t[i] == '0') {
                if (i + k - 1 >= n) {
                    ok = 0;
                    break;
                }
                curr++;
                ends[i + k - 1]++;
            }
            curr -= ends[i];
        }
        if (ok) ans = k;
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}