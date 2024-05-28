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
    int n, k; cin >> n >> k;
    string s; cin >> s;

    bool ok = 1;
    for (int i = 0; i < n; i++)
        if (s[i] > s[i % k])
            ok = 0;
        else if (s[i] < s[i % k])
            break;
    
    if (not ok) {
        int i = k - 1;
        for (; s[i] == '9'; i--)
            s[i] = '0';
        s[i]++;
    }

    for (int i = 0; i < n; i++)
        s[i] = s[i % k];
    cout << n << nl << s << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}