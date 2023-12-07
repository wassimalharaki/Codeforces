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

int32_t main() {
    fast;

    int T; cin >> T;
    
    while (T--) {
        int n, q; cin >> n >> q;

        vi nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        sort(rall(nums));

        vi prefix(n); prefix[0] = nums[0];
        for (int i = 1; i < n; i++)
            prefix[i] = nums[i] + prefix[i - 1];
        
        while (q--) {
            int x; cin >> x;
            auto it = lower_bound(all(prefix), x);
            cout << (it == prefix.end() ? -1 : it - prefix.begin() + 1) nl;
        }
    }

    return 0;
}