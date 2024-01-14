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
    sort(all(nums));
    int sum = accumulate(all(nums), 0ll);

    int m; cin >> m;
    while (m--) {
        int x, y; cin >> x >> y;

        auto it = lower_bound(all(nums), x);
        if (it == nums.end()) --it;        
        int a = *it;
        int answ1 = max(0ll, x - a) + max(0ll, y - (sum - a));
        int answ2 = INF;
        if (it != nums.begin()) {
            it--; a = *it;
            answ2 = max(0ll, x - a) + max(0ll, y - (sum - a));
        }
        cout << min(answ1, answ2) nl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}