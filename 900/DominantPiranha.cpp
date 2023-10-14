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

    int t; cin >> t;
    
    while (t--) {
        int n; cin >> n;

        vi nums(n);
        int max = -1, same = 1;
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            if (i != 0 and nums[i] != nums[i - 1])
                same = 0;
            if (nums[i] > max)
                max = nums[i];
        }

        int imax;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == max && nums[i + 1] != max) {
                imax = i;
                break;
            }
            else if (nums[i] != max && nums[i + 1] == max) {
                imax = i + 1;
                break;
            }
        }
        same ? cout << -1 nl : cout << imax + 1 nl;
    }

    return 0;
}