#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define nl << '\n'
#define pii pair<int, int>
#define v vector
#define vi v<int>
#define vvi v<vi>
#define vpii v<pii>
#define mp make_pair
#define pb push_back
#define INF LONG_LONG_MAX
#define F first
#define S second

void solve() {
    int n; cin >> n;

    vi nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    
    vi prefix(n + 1);
    for (int i = 0; i < n; i++)
        prefix[i + 1] = prefix[i] + nums[i];
    
    sort(all(nums));
    vi prefix_sorted(n + 1);
    for (int i = 0; i < n; i++)
        prefix_sorted[i + 1] = prefix_sorted[i] + nums[i];
    
    int m; cin >> m;

    while (m--) {
        int t, l, r; cin >> t >> l >> r;
        l--;
        cout << (t == 1 ?
            prefix[r] - prefix[l]:
            prefix_sorted[r] - prefix_sorted[l]) nl;
    }
}

int32_t main() {
    fast;

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}