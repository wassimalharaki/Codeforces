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

    v<v<int>> a(n, v<int>(n));
    for (auto& x : a) {
        string s; cin >> s;
        for (int i = 0; i < n; i++)
            x[i] = s[i] == '1';
    }

    v<int> start(n), end(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int curr = 0;
        for (int j = 0; j < n; j++) {
            curr += start[j];
            if (j) curr -= end[j - 1];
            a[i][j] += curr;
        }

        for (int j = 1; j < n; j++)
            if (start[j]) {
                start[j - 1] += start[j];
                start[j] = 0;
            }

        for (int j = n - 2; j >= 0; j--)
            if (end[j]) {
                end[j + 1] += end[j];
                end[j] = 0;
            }
        
        for (int j = 0; j < n; j++)
            if (a[i][j] & 1) {
                ans++;
                start[max(0ll, j - 1)]++;
                end[min(n - 1, j + 1)]++;
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