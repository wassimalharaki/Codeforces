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
    int n, l; cin >> n >> l;

    vi nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    sort(all(nums));

    int max = 0;
    for (int i = 1; i < n; i++)
        max = std::max(nums[i] - nums[i - 1], max);
    
    int bef = 2 * nums[0];
    int aft = 2 * (l - nums[n - 1]);
    cout << setprecision(10) << fixed << std::max({max, bef, aft}) / 2.0;
}

int32_t main() {
    fast;

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}