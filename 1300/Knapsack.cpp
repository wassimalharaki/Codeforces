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
    int n, w; cin >> n >> w;

    vi nums(n);
    for (int& a : nums) cin >> a;

    int curr = 0;
    vi ans;
    for (int i = 0; i < n and curr < (w + 1) / 2; i++)
        if (nums[i] <= (w + 1) / 2)
            curr += nums[i], ans.pb(i + 1);
        else if (nums[i] >= (w + 1) / 2 and nums[i] <= w)
            curr = nums[i], ans.clear(), ans.pb(i + 1);

    if (curr < (w + 1) / 2) {
        cout << -1 nl;
        return;
    }
    cout << ans.size() nl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}