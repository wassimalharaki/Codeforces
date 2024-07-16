#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

const int N = 64;

void solve() {
    int n; cin >> n;

    v<int> a(n);
    for (int& x : a) cin >> x;

    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            for (int k = j; k < n; k++)
                ans = max(ans, a[i] | a[j] | a[k]);
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}