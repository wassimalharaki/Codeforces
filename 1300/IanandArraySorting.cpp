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

    for (int i = 0; i < n - 2; i++)
        if (nums[i + 1] < nums[i]) {
            int diff = nums[i] - nums[i + 1];
            nums[i + 2] += diff;
            nums[i + 1] += diff;
        }
    for (int i = n - 1; i > 1; i--)
        if (nums[i] < nums[i - 1]) {
            int diff = nums[i - 1] - nums[i];
            nums[i - 1] -= diff;
            nums[i - 2] -= diff;
        }
    cout << (is_sorted(all(nums)) ? "YES" : "NO") << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}