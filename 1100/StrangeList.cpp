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
        int n, x; cin >> n >> x;

        vpii nums(n, {0, 1});
        for (pii& a : nums)
            cin >> a.F;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i].F % x)
                break;
            nums.pb(mp(nums[i].F / x, x * nums[i].S));
        }

        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i].F * nums[i].S;
        cout << sum nl;
    }

    return 0;
}