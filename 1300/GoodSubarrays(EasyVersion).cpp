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

    int l = 0, r = 0, ans = 0;
    while (r < n) {
        int sz = r - l + 1;
        if (nums[r] >= sz)
            r++;
        else {
            ans += (sz - 1) * sz / 2;
            while (nums[r] < sz)
                sz = r - ++l + 1;
            sz = r - l + 1;
            ans -= (sz - 1) * sz / 2;
        }
    }
    int a = r - l;
    ans += a * (a + 1) / 2;
    cout << ans nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}