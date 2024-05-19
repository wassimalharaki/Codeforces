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

    int plus = 0, neg = 0, double_neg = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        plus = 0, neg = 0, double_neg = 0;
        for (int j = i; j < n; j++) {
            if (s[j] == '+')
                plus++;
            else if (s[j] == '-') {
                neg++;
                if (j > i and s[j] == s[j - 1])
                    double_neg++;
            }

            if (plus > neg)
                continue;
            if (plus == neg) {
                ans++;
                continue;
            }

            if ((neg - plus) % 3)
                continue;
                
            if ((neg - plus) / 3 <= double_neg)
                ans++;
        }
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