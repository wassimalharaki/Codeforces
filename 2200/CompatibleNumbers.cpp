#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

const int lgN = 22;
const int N = 1 << lgN;

void solve() {
    int n; cin >> n;

    v<int> a(n), dp(N, n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dp[a[i]] = i;
    }
    a.push_back(-1);

    for (int i = 0; i < lgN; i++)
        for (int mask = 0; mask < N; mask++)
            if ((1 << i) & mask)
                dp[mask] = min(dp[mask], dp[mask ^ (1 << i)]);
    
    for (int i = 0; i < n; i++)
        cout << a[dp[a[i] ^ (N - 1)]] << " ";
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}