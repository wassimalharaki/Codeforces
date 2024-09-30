#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;

    v<int> a(n);
    for (int& x : a) cin >> x;
    int mx = *max_element(a.begin(), a.end());

    if (n > 3)
        cout << mx * n << nl;
    else if (n == 3 and (a.front() == mx or a.back() == mx))
        cout << mx * n << nl;
    else if (n == 3)
        cout << max({
            a[0] * 3, a[2] * 3,
            a[0] + abs(a[1] - a[2]) * 2,
            a[2] + abs(a[0] - a[1]) * 2,
            abs(a[1] - a[0]) * 3,
            abs(a[2] - a[1]) * 3,
            abs(a[2] - a[0]) * 3,
            a[0] + a[1] + a[2],
        }) << nl;
    else
        cout << max(abs(a[0] - a[1]) * 2, a[0] + a[1]) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}