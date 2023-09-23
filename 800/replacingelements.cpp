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
        int n, d; cin >> n >> d;

        vi nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];

        sort(all(nums));

        if (nums[n - 1] > d)
            cout << ((nums[0] + nums[1] <= d)? "YES" : "NO") nl;
        else
            cout << "YES" nl;
    }

    return 0;
}