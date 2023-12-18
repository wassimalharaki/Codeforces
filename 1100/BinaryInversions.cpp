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

int32_t main() {
    fast;

    int T; cin >> T;
    
    while (T--) {
        int n; cin >> n;

        vi nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];

        vi dp(n), inv(n);
        dp[0] = nums[0];
        for (int i = 1; i < n; i++) {
            dp[i] = nums[i] + dp[i - 1];
            inv[i] = inv[i - 1];
            nums[i] ?: inv[i] += dp[i];
        }
        
        int answ = inv[n - 1];
        for (int i = 0; i < n; i++) {
            if (nums[i])
                answ = max(answ, inv[n - 1] + dp[i] - 1 - ((n - i) - (dp[n - 1] - dp[i] + 1)));
            else
                answ = max(answ, inv[n - 1] - dp[i] + (n - i) - (dp[n - 1] - dp[i] + 1));
        }
        cout << answ nl;
    }

    return 0;
}