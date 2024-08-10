#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

const int N = 1e4 + 1;

void solve() {
    int n, k; cin >> n >> k;

    v<int> a(n), b(n);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;

    v<bitset<N>> have(N);
    have[0][0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = N - 1 - a[i]; j >= 0; j--)
            have[a[i] + j] = have[a[i] + j] | (have[j] << b[i]);

    int ans = -1;
    for (int i = 1; i < N; i++)
        if (i % k == 0 and have[i][i / k])
            ans = i;
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}