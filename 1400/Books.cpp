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
    int n, k; cin >> n >> k;

    vi pref(n + 1);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        pref[i + 1] = pref[i] + a;
    }

    int ans = 0;
    for (auto it = pref.begin() + 1; it != pref.end(); it++)
        ans = max(ans, it - lower_bound(all(pref), *it - k));
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