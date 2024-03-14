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
    string s; cin >> s;
    string t = "abacaba";

    for (int i = 0; i < n - 6; i++) {
        string u = s;
        for (int j = 0; j < 7; j++)
            if (u[i + j] == '?') u[i + j] = t[j];
        int cnt = 0;
        for (int j = 0; j < n - 6; j++)
            if (u.substr(j, 7) == t)
                cnt++;
        for (char& c : u) if (c == '?') c = 'z';
        if (cnt == 1) {
            cout << "YES" << nl << u << nl;
            return;
        }
    }
    cout << "NO" << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}