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
    int r, x1, y1, x2, y2;
    cin >> r >> x1 >> y1 >> x2 >> y2;
    r <<= 1;

    int a = (x2 - x1), b = (y2 - y1);
    int c = a * a + b * b;
    int d = (c + r * r - 1) / (r * r);
    int lo = 0, hi = 1e5, ans;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        if (mid * mid >= d)
            ans = mid, hi = mid - 1;
        else
            lo = mid + 1;
    }
    cout << ans;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}