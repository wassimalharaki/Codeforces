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

    vpii ans;
    if (nums[0] & 1) {
        int r;
        for (int i = 0; i < n; i++)
            if (nums[i] & 1)
                r = i;
        
        for (int i = 0; i < n; i++)
            if ((nums[i] & 1) and nums[i] != nums[r])
                ans.pb(mp(i, r)), nums[i] = nums[r];
        
        for (int i = 0; i < n; i++)
            if (!(nums[i] & 1))
                ans.pb(mp(0, i));
    }
    else {
        int r;
        for (int i = 0; i < n; i++)
            if (!(nums[i] & 1))
                r = i;
            
        for (int i = 0; i < n; i++)
            if (!(nums[i] & 1) and nums[i] != nums[r])
                ans.pb(mp(i, r)), nums[i] = nums[r];
        
        for (int i = 0; i < n; i++)
            if (nums[i] & 1)
                ans.pb(mp(0, i));
    }

    cout << ans.size() nl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].F + 1 << " " << ans[i].S + 1 nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}