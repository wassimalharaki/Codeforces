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

    int lo = 0, hi = 3e9, ans;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        if (mid * (mid - 1) / 2 <= n)
            lo = mid + 1, ans = mid;
        else
            hi = mid - 1;
    }
    cout << ans + n - ans * (ans - 1) / 2 nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}