#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

const int N = 1e6 + 1;
const int mod = 998244353;
v<int> dp1(N), dp2(N), dp3(N), dp4(N);

void solve() {
    int n; cin >> n;
    cout << dp1[n] << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 1; i < N; i++)
        dp3[i] = ((i + 3) * dp3[i - 1] % mod + i + 1) % mod;
    for (int i = 0; i < N - 1; i++)
        dp2[i] = (dp3[i + 1] - dp3[i] + mod) % mod;

    dp4[0] = 1;
    for (int i = 1; i < N - 1; i++)
        dp4[i] = (dp4[i - 1] + dp2[i - 1]) % mod;

    dp1[2] = 1, dp1[3] = 2;
    for (int i = 4; i < N; i++)
        dp1[i] = (dp1[i - 1] + dp4[i - 3]) % mod;

    int T = 1;
    cin >> T;
    while (T--) solve();
}