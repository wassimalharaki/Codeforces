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
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        nums[a]++;
        sum += a;
    }

    map<int, int> curr;
    curr[sum] = 1;
    for (auto it = curr.rbegin(); it != curr.rend(); it++) {
        auto& [key, val] = *it;

        if (not nums.count(key)) {
            curr[key / 2] += val;
            curr[(key + 1) / 2] += val;
            val = 0;
            continue;
        }

        if (nums[key] == val) continue;

        if (nums[key] > val) {
            cout << "NO" << nl;
            return;
        }

        int a = val - nums[key];
        curr[key / 2] += a;
        curr[(key + 1) / 2] += a;
        val = nums[key];
    }

    for (auto& [key, val] : nums)
        if (curr[key] != val) {
            cout << "NO" << nl;
            return;
        }
    cout << "YES" << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}