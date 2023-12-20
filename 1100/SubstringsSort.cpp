#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define nl << '\n'
#define pii pair<int, int>
#define v vector
#define vi v<int>
#define vvi v<vi>
#define vpii v<pii>
#define mp make_pair
#define pb push_back
#define INF LONG_LONG_MAX
#define F first
#define S second

bool substring(string& s1, string& s2) {
    int longest = 0;
    int n = s2.size(), m = s1.size();

    vvi dp(n + 1, vi(m + 1));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (s2[i] == s1[j])
                dp[i + 1][j + 1] = dp[i][j] + 1;
            else
                dp[i + 1][j + 1] = 0;
            longest = max(longest, dp[i + 1][j + 1]);
        }
    return longest == m;
}

int32_t main() {
    fast;

    int n; cin >> n;

    v<string> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    sort(all(s), [](string& s1, string& s2) -> bool {
        return s1.size() < s2.size();
    });
    
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (not substring(s[i], s[j])) {
                cout << "NO" nl;
                return 0;
            }
    
    cout << "YES" nl;
    for (int i = 0; i < n; i++)
        cout << s[i] nl;

    return 0;
}