#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;

    v<int> a(n);
    for (int& x : a) cin >> x;
    int k; cin >> k;
    for (int& x : a) x -= k;
    
    int ans = n, curr = 0, l = 0;
    v<int> pmax(n + 1);
    for (int i = 1; i <= n; i++) {
        curr += a[i - 1];
        pmax[i] = max(pmax[i - 1], curr);
        if (i - 2 >= 0 and i - 2 >= l and curr - pmax[i - 2] < 0)
            ans--, curr = 0, l = i, pmax[i] = 0;
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