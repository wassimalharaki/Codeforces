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
        int n; cin >> n;

        v<pii> nums(n);

        for (int i = 0; i < n; i++) {
            cin >> nums[i].F;
            nums[i].S = i;
        }

        sort(all(nums));

        int answ = -1;
        int skip = -1;

        for (int i = 0; i < n - 1; i++)
            if (nums[i].F != skip && nums[i].F != nums[i + 1].F) {
                answ = nums[i].S + 1;
                break;
            }
            else
                skip = nums[i].F;
        if (answ == -1 && nums[n - 1].F != skip)
            answ = nums[n - 1].S + 1;
        cout << answ nl;
    }

    return 0;
}