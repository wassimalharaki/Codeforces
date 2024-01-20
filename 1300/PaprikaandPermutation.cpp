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

    v<bool> perm(n + 1);
    for (int i = 0; i < n; i++)
        if (nums[i] <= n)
            perm[nums[i]] = 1;
    
    vi missing;
    for (int i = 1; i <= n; i++)
        if (not perm[i])
            missing.pb(i);
    
    fill(all(perm), 0);
    vi have;
    for (int i = 0; i < n; i++)
        if (nums[i] <= n and not perm[nums[i]])
            perm[nums[i]] = 1;
        else
            have.pb(nums[i]);

    for (int i = 0; i < missing.size(); i++)
        if (missing[i] > (have[i] - 1) / 2) {
            cout << -1 nl;
            return;
        }
    cout << missing.size() nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}