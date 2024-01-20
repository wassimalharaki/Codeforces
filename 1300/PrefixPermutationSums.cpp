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
    int n; cin >> n;

    vi nums(n - 1);
    for (int& a : nums) cin >> a;

    vi ok(n + 1), over;
    for (int i = 0; i < n - 1; i++) {
        int diff = (i ? nums[i] - nums[i - 1] : nums[i]);
        if (diff <= n and not ok[diff])
            ok[diff]++;
        else
            over.pb(diff);
    }

    if (over.size() > 1) {
        cout << "NO" << nl;
        return;
    }

    if (over.size() == 0) {
        cout << "YES" << nl;
        return;
    }

    vi missing;
    for (int i = 1; i <= n; i++)
        if (not ok[i])
            missing.pb(i);
    
    if (missing.size() > 2) {
        cout << "NO" << nl;
        return;
    }

    if (over[0] == accumulate(all(missing), 0ll))
        cout << "YES" << nl;
    else
        cout << "NO" << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}