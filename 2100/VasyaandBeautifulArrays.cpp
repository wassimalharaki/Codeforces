#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

const int N = 1e6 + 1;

void solve() {
    int n, k; cin >> n >> k;

    v<int> a(N);
    for (int i = 0; i < n; i++) {
        int x; cin >> x; a[x] = 1;
    }
    v<int> pref(N + 1);
    partial_sum(a.begin(), a.end(), pref.begin() + 1);

    int ans = 1;
    for (int i = 2; i < N; i++) {
        if (pref[i]) continue;
        bool ok = 1;
        for (int j = i; j < N; j += i)
            ok &= pref[min(N, j + i)]
                - pref[min({N, j + i, j + k + 1})] == 0;
        if (ok) ans = i;
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}