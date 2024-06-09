#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n; cin >> n;

    v<array<int, 2>> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i][0], a[i][1] = i + 1;
    sort(a.rbegin(), a.rend());

    v<array<int, 2>> diff(25e5, {-1, -1});
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            int x = a[i][0] - a[j][0];
            if (diff[x][0] == -1) {
                diff[x] = {a[i][1], a[j][1]};
                continue;
            }
            if (diff[x][0] == a[i][1] or diff[x][0] == a[j][1] or
                    diff[x][1] == a[i][1] or diff[x][1] == a[j][1])
                continue;
                
            cout << "YES" << nl;
            cout << diff[x][0] << " " << a[j][1] << " "
                 << a[i][1] << " " << diff[x][1];
            return;
        }
    cout << "NO" << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}