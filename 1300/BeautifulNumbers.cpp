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

    vi nums(n);
    for (int& a : nums) cin >> a;

    vi ans(n);
    int l = find(all(nums), 1ll) - nums.begin(), r = l, max = 1;
    ans[0] = 1;
    for (int i = 1; i < n; i++) {
        if (l == 0)
            r++, max = std::max(max, nums[r]);
        else if (r == n - 1)
            l--, max = std::max(max, nums[l]);
        else {
            if (nums[l - 1] < nums[r + 1])
                l--, max = std::max(max, nums[l]);
            else
                r++, max = std::max(max, nums[r]);
        }
        if (max == i + 1)
            ans[i] = 1;
    }

    for (int& i : ans)
        cout << i;
    cout << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}