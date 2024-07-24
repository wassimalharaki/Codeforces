#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

const int N = 6;

void solve() {
    v<int> a(N);
    for (int& x : a) cin >> x;

    int n; cin >> n;
    v<array<int, 2>> b(N * n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        for (int j = 0; j < N; j++)
            b[i * 6 + j] = {x - a[j], i};
    }
    sort(b.begin(), b.end());

    v<int> cnt(n);
    int l = 0, r = 0, have = 0, ans = 1e18;
    while (r < n * N)
        if (have < n)
            have += cnt[b[r++][1]]++ == 0;
        else
            ans = min(ans, b[r - 1][0] - b[l][0]),
            have -= --cnt[b[l++][1]] == 0;
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}