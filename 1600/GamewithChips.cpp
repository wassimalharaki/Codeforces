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
    int n, m, k; cin >> n >> m >> k;

    for (int i = 0; i < k; i++) {
        int x, y; cin >> x >> y;
    }

    string s;
    for (int i = 0; i < n - 1; i++)
        s += 'U';
    for (int i = 0; i < m - 1; i++)
        s += 'L';
    
    bool alt = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - 1; j++)
            s += (alt ? 'R' : 'L');
        s += 'D'; alt = !alt;
    }
    cout << s.size() << nl << s;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}