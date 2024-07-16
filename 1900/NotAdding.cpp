#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

const int N = 1e6 + 1;

void solve() {
    int n; cin >> n;

    v<int> cnt(N);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        cnt[x]++;
    }

    int ans = 0;
    for (int i = N - 1; i; i--) {
        if (cnt[i]) continue;
        int g = 0;
        for (int j = 2 * i; j < N; j += i)
            if (cnt[j])
                g = gcd(g, j);
        if (g == i) {
            cnt[i] = 1;
            ans++;
        }
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