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
    int n, c; cin >> n >> c;

    v<int> a(n), b(n);
    for (int i = 1; i < n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
        cin >> b[i];
    
    array<int, 2> prev{0, c};
    for (int i = 0; i < n; i++) {
        int x = a[i] + min(prev[0], prev[1]);
        int y = b[i] + min(prev[1], c + prev[0]);
        prev = {x, y};
        cout << min(x, y) << " ";
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}