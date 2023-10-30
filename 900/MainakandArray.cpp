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

int32_t main() {
    fast;

    int T; cin >> T;
    
    while (T--) {
        int n; cin >> n;

        vi nums(n);
        int min = INF;
        int mx = 0;
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            if (i and nums[i] > mx)
                mx = nums[i];
            if (i != n - 1 and nums[i] < min)
                min = nums[i];
        }
        int answ = max(max(nums[n - 1] - min, mx - nums[0]), nums[n - 1] - nums[0]);

        for (int i = 0; i < n - 1; i++)
            answ = max(answ, nums[i] - nums[i + 1]);
        cout << answ nl;
    }

    return 0;
}