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
        string s; cin >> s;

        if (s[0] == 'M') {
            cout << "NO" nl;
            continue;
        }

        if (count(all(s), 'T') != 2 * count(all(s), 'M')) {
            cout << "NO" nl;
            continue;
        }

        vpii dp(n, mp(0, 0));
        dp[0] = mp(1, 0);
        for (int i = 1; i < n; i++) {
            if (s[i] == 'T') {
                dp[i].F = 1 + dp[i - 1].F;
                dp[i].S = dp[i - 1].S;
            }
            else {
                dp[i].F = dp[i - 1].F;
                dp[i].S = 1 + dp[i - 1].S;
            }
        }

        string answ = "YES"; int sub = 0, subright = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'T') {
                subright = max(subright - 1, 0ll);
                continue;
            }

            int leftTs = dp[i].F - sub;
            int Ms = dp[i].S - sub;
            int rightTs = dp[n - 1].F - dp[i].F - subright;
            if (leftTs < Ms or rightTs < Ms) {
                answ = "NO";
                break;
            }
            sub++;
            subright++;
        }
        cout << answ nl;
    }

    return 0;
}