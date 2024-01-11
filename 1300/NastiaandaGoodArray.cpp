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
    for (int& a : nums) cin >> a;

    int imin = min_element(all(nums)) - nums.begin();
    int min = nums[imin], prev = min + 1;
    vvi ops;
    for (int i = imin + 1; i < n; i++)
        ops.pb({imin + 1, i + 1, min, prev++});
    prev = min + 1;
    for (int i = imin - 1; i >= 0; i--)
        ops.pb({imin + 1, i + 1, min, prev++});
    cout << ops.size() nl;
    for (int i = 0; i < ops.size(); i++) {
        for (int j = 0; j < 4; j++)
            cout << ops[i][j] << " ";
        cout nl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}