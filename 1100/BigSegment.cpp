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
    int n; cin >> n;

    vvi nums(n, vi(3));
    for (int i = 0; i < n; i++)
        cin >> nums[i][0] >> nums[i][1], nums[i][2] = i + 1;
    sort(all(nums), [](vi& l, vi& r) -> bool {
        if (l[0] == r[0])
            return l[1] < r[1];
        return l[0] < r[0];
    });

    int l = nums[0][0], r, ind;
    for (int i = 0; i < n and nums[i][0] == l; i++)
        r = nums[i][1], ind = nums[i][2];

    int max = 0;
    for (int i = 0; i < n; i++)
        max = std::max(max, nums[i][1]);
    
    cout << (r >= max ? ind : -1);
}

int32_t main() {
    fast;

    int T = 1;
    // cin >> T;

    while (T--)
        solve();

    return 0;
}