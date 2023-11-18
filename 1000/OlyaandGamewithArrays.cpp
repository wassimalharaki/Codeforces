#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define nl << '\n'
#define v vector
#define vi vector<int>
#define pii pair<int, int>
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

        v<pii> nums(n);
        for (int i = 0; i < n; i++) {
            int m; cin >> m;
            int m1 = INF, m2 = INF;
            for (int j = 0; j < m; j++) {
                int a; cin >> a;
                if (a < m1)
                    m2 = m1, m1 = a;
                else if (a < m2)
                    m2 = a;
            }
            nums[i].F = m1; nums[i].S = m2;
        }
        sort(all(nums));

        int sum = 0, least = INF;
        for (int i = 0; i < n; i++)
            sum += nums[i].S, least = min(least, nums[i].S);
        sum += nums[0].F - least;
        cout << sum nl;
    }

    return 0;
}