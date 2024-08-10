#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;

    v<array<int, 3>> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i][0] >> a[i][1], a[i][2] = i + 1;
    sort(a.begin(), a.end(), [](auto& l, auto& r) {
        if (l[0] == r[0])
            return l[1] > r[1];
        return l[0] < r[0];
    });

    array<int, 2> curr{a[0][0], a[0][1]};
    for (int i = 1; i < n; i++) {
        if (a[i][1] <= curr[1]) {
            cout << a[i][2] << nl;
            return;
        }
        if (i < n - 1 and a[i + 1][1] >= a[i][1]
                and a[i + 1][0] <= max(a[i][0], curr[1] + 1)) {
            cout << a[i][2] << nl;
            return;
        }
        if (a[i][0] > curr[1])
            curr = {a[i][0], a[i][1]};
        else
            curr[1] = max(curr[1], a[i][1]);
    }
    cout << -1 << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}