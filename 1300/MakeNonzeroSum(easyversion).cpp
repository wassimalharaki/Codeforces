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

    if (n & 1) {
        cout << -1 nl;
        return;
    }

    vpii ans;
    for (int i = 0; i < n; i += 2)
        if (nums[i] * nums[i + 1] < 0) {
            ans.pb(mp(i + 1, i + 1));
            ans.pb(mp(i + 2, i + 2));
        }
        else
            ans.pb(mp(i + 1, i + 2));
    cout << ans.size() nl;
    for (pii& a : ans)
        cout << a.F << " " << a.S nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}