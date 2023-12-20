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
        vi nums(3);
        int m;
        cin >> nums[0] >> nums[1] >> nums[2] >> m;
        sort(all(nums));

        int max = accumulate(all(nums), -3ll);
        int min = nums[2] - (nums[1] + nums[0] + 1);
        cout << (min <= m and m <= max ? "YES" : "NO") nl;
    }

    return 0;
}