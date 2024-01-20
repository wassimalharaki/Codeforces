#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF LONG_LONG_MAX
#define nl '\n'
#define v vector
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define mp make_pair
#define F first
#define S second

using pii = pair<int, int>;
using vi = v<int>;
using vvi = v<vi>;
using vpii = v<pii>;

bool is_palindrome(string& s, int n) {
    if (!(n & 1)) return 0;
    for (int i = 0; i < n / 2; i++)
        if (s[i] != s[n - i - 1])
            return 0;
    return 1;
}

bool contains(string& s, string& t) {
    int n = s.size(), m = t.size();
    if (m > n) return 0;
    vvi dp(n + 1, vi(m + 1));
    int max = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                max = std::max(max, dp[i][j]);
            }
    return max == m;
}

void solve() {
    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();

    {
        int r = 0;
        for (int i = 0; i < m; i++)
            if (is_palindrome(t, i + 1))
                r = i + 1;
        string u;
        for (int i = r; i < m; i++)
            u.pb(t[i]);
        reverse(all(u));

        for (int i = 0; i <= r / 2; i++)
            u.pb(t[i]);
        
        if (contains(s, u)) {
            cout << "YES" << nl;
            return;
        }
    }

    {
        reverse(all(t));
        int r = 0;
        for (int i = 0; i < m; i++)
            if (is_palindrome(t, i + 1))
                r = i + 1;
        
        string u;
        for (int i = r / 2; i < m; i++)
            u += t[i];
        reverse(all(u));

        if (contains(s, u)) {
            cout << "YES" << nl;
            return;
        }
    }
    cout << "NO" << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}