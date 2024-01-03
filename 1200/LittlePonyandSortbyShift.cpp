#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF LONG_LONG_MAX
#define nl << '\n'
#define v vector
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define mp make_pair
#define F first
#define S second

using pii = pair<int, int>;
using vi = v<int>;
using vvi = v<vi>;
using vpii = v<pii>;

void solve() {
    int n; cin >> n;

    vi nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    
    v<pair<int, pii>> count;
    for (int i = 0; i < n;) {
        count.pb(mp(1, mp(nums[i], nums[i])));
        int sz = count.size() - 1;
        while (++i < n and nums[i] >= nums[i - 1]) {
            count[sz].F++;
            count[sz].S.F = max(count[sz].S.F, nums[i]);
            count[sz].S.S = min(count[sz].S.S, nums[i]);
        }    
    }
    if (count.size() == 1)
        cout << 0;
    else if (count.size() == 2)
        cout << (count[0].S.S >= count[1].S.F ? count[1].F : -1);
    else
        cout << -1;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}