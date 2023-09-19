#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define all(v) v.begin(), v.end()
#define nl << '\n'
#define v vector
#define vi vector<int>
#define pii pair<int, int>

int32_t main() {
    fast

    int t;

    cin >> t;

    while(t--) {
        int n;

        cin >> n;

        int min = LONG_LONG_MAX;

        vi nums(n);

        for (int i = 0; i < n; i++)
            cin >> nums[i];
        sort(all(nums));

        for (int i = 0; i < n - 1; i++) {
            if (nums[i + 1] - nums[i] < min)
                min = nums[i + 1] - nums[i];
        }

        cout << min nl;
    }

    return 0;
}