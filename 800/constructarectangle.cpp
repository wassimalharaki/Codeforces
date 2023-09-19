#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define all(v) v.begin(), v.end()
#define nl << '\n'
#define v vector
#define vi vector<int>
#define pii pair<int, int>
#define mp make_pair
#define INF LONG_LONG_MAX
#define F first
#define S second

int32_t main() {
    fast

    int t; cin >> t;

    while (t--) {
        vi nums(3); cin >> nums[0] >> nums[1] >> nums[2];

        sort(all(nums));

        if (nums[2] == nums[1] + nums[0])
            cout << "YES" nl;
        else if (nums[0] == nums[1] && not (nums[2] & 1))
            cout << "YES" nl;
        else if (nums[1] == nums[2] && not (nums[0] & 1))
            cout << "YES" nl;
        else
            cout << "NO" nl;
    }

    return 0;
}