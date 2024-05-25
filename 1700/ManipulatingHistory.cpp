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

    v<int> cnt(26);
    for (int i = 0; i < 2 * n + 1; i++) {
        string s; cin >> s;
        for (char& c : s)
            cnt[c - 'a']++;
    }
    
    for (int i = 0; i < 26; i++)
        if (cnt[i] & 1) {
            cout << char('a' + i) << nl;
            return;
        }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}