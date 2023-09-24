#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define all(v) v.begin(), v.end()
#define nl << '\n'
#define v vector
#define vi vector<int>
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define INF LONG_LONG_MAX
#define F first
#define S second

bool check(v<vi>& nums) {
    return nums[0][0] < nums[0][1]
            && nums[1][0] < nums[1][1]
            && nums[0][0] < nums[1][0]
            && nums[0][1] < nums[1][1];
}

int32_t main() {
    fast;

    int t; cin >> t;
    
    while (t--) {
        v<vi> nums(2, vi(2));
        cin >> nums[0][0] >> nums[0][1] >> nums[1][0] >> nums[1][1];

        string answ = "NO";
        for (int i = 0; i < 4; i++) {
            if (check(nums)) {
                answ = "YES";
                break;
            }
            int temp = nums[0][0];
            nums[0][0] = nums[1][0];
            nums[1][0] = nums[1][1];
            nums[1][1] = nums[0][1];
            nums[0][1] = temp;
        }
        cout << answ nl;
    }

    return 0;
}