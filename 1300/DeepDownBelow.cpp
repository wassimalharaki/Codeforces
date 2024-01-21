#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF LONG_LONG_MAX
#define nl '\n'
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

    v<pair<int, vi>> nums(n);
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        nums[i].S.resize(k);
        for (int j = 0; j < k; j++)
            cin >> nums[i].S[j], nums[i].S[j] -= j;
        nums[i].F = *max_element(all(nums[i].S));
    }

    sort(all(nums), [](pair<int, vi>& l, pair<int, vi>& r) -> bool {
        if (l.F == r.F)
            return l.S.size() > r.S.size();
        return l.F < r.F;
    });

    int ans = -INF, sum = 0;
    for (int i = 0; i < n; i++) {
        auto& [max, monst] = nums[i];
        ans = std::max(ans, max - sum + 1);
        sum += monst.size();
    }
    cout << ans << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}