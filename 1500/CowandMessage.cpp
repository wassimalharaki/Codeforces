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

    v<v<int>> pref(n + 1, v<int>(26));
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i];
        pref[i + 1][s[i] - 'a']++;
    }

    int ans = 1;
    map<char, int> ok;
    for (char& c : s)
        ans = max(ans, ++ok[c]);

    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++) {
            int curr = 0;
            for (int k = 0; k < n; k++) {
                if (s[k] != char(i + 'a')) continue;
                curr += pref[n][j] - pref[k + 1][j];
            }
            ans = max(curr, ans);
        }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}