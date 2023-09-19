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
        int n = 7;

        vi nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];

        cout << nums[0] << " " << nums[1] << " " << ((nums[2] == nums[0] + nums[1])? nums[3] : nums[2]) nl;
    }

    return 0;
}