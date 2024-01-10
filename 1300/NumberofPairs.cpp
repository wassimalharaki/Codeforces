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
    int n, l, r; cin >> n >> l >> r;

    vi nums(n);
    for (int& a : nums) cin >> a;
    sort(all(nums));
    if (n == 1) {
        cout << 0 nl;
        return;
    }

    int answ = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] >= r) continue;
        int min = max(1ll, l - nums[i]);
        int max = r - nums[i];
        auto it1 = upper_bound(all(nums), max);
        auto it2 = lower_bound(all(nums), min);
        if (it1 == nums.begin() or it2 == nums.end()) continue;
        answ += it1 - it2;
        if (*it2 <= nums[i] and nums[i] <= *(--it1)) answ--;
    }
    cout << answ / 2 nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}