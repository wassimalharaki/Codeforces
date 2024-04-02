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

    v<int> a(n), b(n);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;

    v<int> prefix(n + 1);
    for (int i = 0; i < n; i++)
        prefix[i + 1] = prefix[i] + a[i] * b[i];

    v<v<int>> revs(n, v<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - i; j++) {
                int x = a[j] * b[j + i];
                int y = (j == j + i ? 0 : a[j + i] * b[j]);
                revs[j][j + i] = x + y;
                if (j + 1 <= j + i - 1)
                    revs[j][j + i] += revs[j + 1][j + i - 1];
        }
    
    int ans = prefix[n];
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++) {
            int x = prefix[n] - prefix[j + 1] + prefix[i];
            ans = max(ans, x + revs[i][j]);
        }
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}