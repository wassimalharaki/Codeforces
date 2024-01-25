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

    vi nums(n);
    for (int& a : nums) cin >> a;

    vvi splits{{nums[0]}};
    for (int i = 1; i < n; i++)
        if (nums[i] > nums[i - 1])
            splits.back().pb(nums[i]);
        else
            splits.pb({nums[i]});
    
    bool ok = 1;
    int curr = splits[0][0];
    for (vi& split : splits)
        ok = split.back() > curr;
    cout << (ok ? "YES" : "NO") << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}