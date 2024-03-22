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

string rgb = "RGB";

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;

    int ans = INT_MAX;
    for (int i = 0; i < 3; i++) {
        int curr = 0;
        for (int j = 0; j < k; j++)
            curr += s[j] != rgb[j % 3];
        ans = min(ans, curr);
        for (int j = k; j < n; j++) {
            curr -= s[j - k] != rgb[(j - k) % 3];
            curr += s[j] != rgb[j % 3];
            ans = min(ans, curr);
        }
        rgb = rgb.substr(1, 3) + rgb[0];
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