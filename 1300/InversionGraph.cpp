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

    v<bool> ok(n, 1);
    vi nums(n);
    for (int& a : nums) cin >> a;

    int look = n, ans = 0, min = INF, curr = INF;
    for (int i = n - 1; i >= 0; i--) {
        curr = std::min(nums[i], curr);
        ok[nums[i] - 1] = 0;
        if (nums[i] != look) continue;
        if (min >= nums[i]) ans++;
        min = std::min(min, curr);
        curr = INF;
        while (look >= 1 and ok[look - 1] == 0)
            look--;
        if (look == 0)
            break;
    }
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