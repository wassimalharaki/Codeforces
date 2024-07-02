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
    int n, m, k; cin >> n >> m >> k;

    v<array<int, 3>> a(k);
    for (int i = 0; i < k; i++)
        cin >> a[i][0] >> a[i][1], a[i][2] = i;
    sort(a.begin(), a.end());

    v<int> b(k + 1); b[k] = m;
    for (int i = k - 1; i >= 0; i--)
        b[i] = min(b[i + 1], a[i][1] - 1);
    int max = b[0] * a[0][0];
    for (int i = 1; i < k; i++)
        max += b[i] * (a[i][0] - a[i - 1][0]);
    max += m * (n - a[k - 1][0]);

    cout << max << nl;
    v<int> ans(k);
    for (int i = 0; i < k; i++)
        if (a[i][1] > b[i + 1])
            ans[a[i][2]] = 0;
        else {
            if (i == 0)
                ans[a[i][2]] = 1;
            else if (a[i][0] - a[i - 1][0])
                ans[a[i][2]] = 1;
            else
                ans[a[i][2]] = 0;
        }
    for (int& i : ans)
        cout << i << " ";
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}