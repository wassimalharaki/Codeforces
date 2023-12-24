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

void solve() {
    vi nums(3);
    cin >> nums[0] >> nums[1] >> nums[2];
    sort(rall(nums));
    int answ = nums[2];
    int diff = nums[0] - nums[1];
    nums[0] -= min(diff, nums[2]);
    nums[2] -= min(diff, nums[2]);
    nums[0] -= (nums[2] + 1) / 2;
    nums[1] -= nums[2] / 2;
    cout << answ + min(nums[0], nums[1]) nl;
}

int32_t main() {
    fast;

    int T = 1;
    cin >> T;

    while(T--)
        solve();

    return 0;
}