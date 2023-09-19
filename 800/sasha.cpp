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

        for (int i = 0; i < n; i++)
            cin >> nums[i];

        int colors = n / 2;
        sort(all(nums));
        int sum = 0;
        for (int i = 0, j = n - 1; i < n / 2; i++, j--) {
            sum += nums[j] - nums[i];
        }

        cout << sum nl;
    }

    return 0;
}