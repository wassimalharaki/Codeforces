#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    string s; cin >> s;
    int n = s.size();

    v<array<int, 2>> b{{s[0] - 'a', 1}};
    for (int i = 1; i < n; i++)
        if (s[i] - 'a' == b.back()[0])
            b.back()[1]++;
        else
            b.push_back({s[i] - 'a', 1});
    
    int dp[2][2];
    memset(dp, 0, sizeof(dp));
    int curr = 0, o = 0, e = 0;
    for (auto& [x, y] : b) {
        o += (y + (y & 1)) * (y / 2 + 1) / 2;
        e += (y - 1 + !(y & 1)) * ((y + 1) / 2) / 2;

        if (curr & 1) {
            e += y / 2 * dp[x][1];
            o += (y + 1) / 2 * dp[x][1];
            e += (y + 1) / 2 * dp[x][0];
            o += y / 2 * dp[x][0];

            dp[x][0] += y / 2;
            dp[x][1] += (y + 1) / 2;
        }
        else {
            e += (y + 1) / 2 * dp[x][1];
            o += y / 2 * dp[x][1];
            e += y / 2 * dp[x][0];
            o += (y + 1) / 2 * dp[x][0];

            dp[x][0] += (y + 1) / 2;
            dp[x][1] += y / 2;
        }

        curr += y;
    }
    cout << e << " " << o << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}