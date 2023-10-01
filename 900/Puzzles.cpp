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

    int n, m; cin >> n >> m;

    vi nums(m);
    for (int i = 0; i < m; i++)
        cin >> nums[i];
    sort(all(nums));

    int min = INF;
    for (int i = 0; i + n - 1 < m; i++)
        if (nums[i + n - 1] - nums[i] < min)
            min = nums[i + n - 1] - nums[i];
    cout << min;

    return 0;
}