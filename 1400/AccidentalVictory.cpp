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

    vpii nums(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> nums[i].F;
        nums[i].S = i + 1;
        sum += nums[i].F;
    }
    sort(rall(nums));

    vi ans;
    ans.pb(nums[0].S);
    int prev = 0;
    sum -= nums[0].F;
    for (int i = 1; i < n; i++) {
        if (sum >= nums[prev].F) {
            ans.pb(nums[i].S);
            prev = i;
        }
        sum -= nums[i].F;
    }
    sort(all(ans));
    
    cout << ans.size() << nl;
    for (int& i : ans)
        cout << i << " ";
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