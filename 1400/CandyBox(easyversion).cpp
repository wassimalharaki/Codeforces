#include <bits/stdc++.h>

using namespace std;

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

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

    map<int, int> nums;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        nums[a]++;
    }

    vi counts;
    for (auto& [key, val] : nums)
        counts.pb(val);
    sort(rall(counts));

    unordered_set<int> used;
    int prev, avail = 0;
    int ans = 0;
    for (int i = 0; i < counts.size(); i++) {
        if (used.count(counts[i])) {
            avail++;
            continue;
        }
        used.insert(counts[i]);
        ans += counts[i];
        if (avail) {
            int use = min(avail, prev - counts[i] - 1);
            int add = (2 * prev - 1 - use) * use / 2;
            ans += add;
            avail -= use;
        }
        prev = counts[i];
    }
    int use = min(avail, prev - 1);
    int add = (2 * prev - 1 - use) * use / 2;
    ans += add;
    cout << ans << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}