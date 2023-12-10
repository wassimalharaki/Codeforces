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
        int neg = 0;
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            if (nums[i] <= 0) neg++;
        }
        sort(all(nums));
        
        if (neg == 0) {
            cout << 1 nl;
            continue;
        }

        int diff = INF;
        for (int i = 1; i < n; i++) {
            if (nums[i] > 0)
                break;
            diff = min(diff, nums[i] - nums[i - 1]);
        }


        int find = -1;
        for (int i = 0; i < n; i++)
            if (nums[i] >= 0 and nums[i] <= diff)
                find = nums[i];

        cout << (find > 0 ? neg + 1 : neg) nl;
    }

    return 0;
}