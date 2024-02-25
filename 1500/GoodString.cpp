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
    string s; cin >> s;
    int n = s.size();

    v<v<int>> digits(10);
    for (int i = 0; i < n; i++)
        digits[s[i] - '0'].push_back(i);

    int ans = n;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++) {
            int sz = 0, prev = -1;
            while (1) {
                auto it = upper_bound(all(digits[i]), prev);
                if (it == digits[i].end()) break;
                sz++; prev = *it;
                it = upper_bound(all(digits[j]), prev);
                if (it == digits[j].end()) break;
                sz++; prev = *it;
            }
            if (sz & 1) sz--;
            ans = min(ans, n - sz);
        }
    
    for (int i = 0; i < 10; i++)
        ans = min(ans, n - (int) digits[i].size());
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}