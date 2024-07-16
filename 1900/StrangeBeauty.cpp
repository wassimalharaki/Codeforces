#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

const int N = 2e5 + 1;

void solve() {
    int n; cin >> n;

    v<int> a(n), cnt(N), dp(N);
    for (int& x : a)
        cin >> x, cnt[x]++;

    for (int i = 1; i < N; i++) {
        dp[i] += cnt[i];
        for (int j = 2 * i; j < N; j += i)
            dp[j] = max(dp[j], dp[i]);
    }
    cout << n - *max_element(dp.begin(), dp.end()) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}