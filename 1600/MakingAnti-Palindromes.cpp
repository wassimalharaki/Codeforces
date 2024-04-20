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

    v<int> letters(26);
    for (int i = 0; i < n; i++)
        letters[s[i] - 'a']++;
    
    for (int i = 0; i < 26; i++)
        if (letters[i] > n / 2 or (n & 1)) {
            cout << -1 << nl;
            return;
        }
    
    int ans = 0;
    v<int> diff(26);
    for (int i = 0; i < n / 2; i++)
        if (s[i] == s[n - i - 1])
            ans++, diff[s[i] - 'a']++;
            
    ans = (ans + 1) / 2;
    for (int i = 0; i < 26; i++)
        ans = max(ans, diff[i]);
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}