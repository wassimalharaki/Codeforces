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
    int n, k; cin >> n >> k;

    vpii nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i].F >> nums[i].S;
    sort(all(nums), [](pii& l, pii& r) -> bool {
        if (l.F != r.F)
            return l.F > r.F;
        return l.S < r.S;
    });

    int count = 0;
    int p = nums[k - 1].F, t = nums[k - 1].S;
    for (int i = 0; i < n; i++)
        if (nums[i].F == p and nums[i].S == t)
            count++;
    cout << count nl;
}

int32_t main() {
    fast;

    int T = 1;
    // cin >> T;

    while(T--)
        solve();

    return 0;
}