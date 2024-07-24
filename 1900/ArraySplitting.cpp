#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, k; cin >> n >> k;

    v<int> a(n), suff(n);
    for (int& x : a) cin >> x;
    partial_sum(a.rbegin(), a.rend(), suff.rbegin());

    int ans = suff[0];
    suff.erase(suff.begin());
    sort(suff.rbegin(), suff.rend());
    for (int i = 0; i < k - 1; i++)
        ans += suff[i];
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}