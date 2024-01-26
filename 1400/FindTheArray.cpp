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

    int even = 0, odd = 0;
    for (int i = 0; i < n; i++)
        i & 1 ? odd += nums[i] : even += nums[i];
    
    if (even > odd)
        for (int i = 0; i < n; i++)
            cout << (i & 1 ? 1 : nums[i]) << " ";
    else
        for (int i = 0; i < n; i++)
            cout << (i & 1 ? nums[i] : 1) << " ";
    cout << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}