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

int32_t main() {
    fast

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        vi nums(n);

        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        sort(all(nums));
        int answ = -1;

        for (int i = 0; i < n - 2; i++) {
            if (nums[i] == nums[i + 1] && nums[i + 1] == nums[i + 2]) {
                answ = nums[i];
                break;
            }
        }
        cout << answ nl;
    }

    return 0;
}