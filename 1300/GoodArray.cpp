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

    map<int, vi> map;
    vi nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        map[nums[i]].pb(i + 1);
    }
    sort(all(nums));

    int sum = accumulate(all(nums), 0ll);
    vi ans;
    
    {
        int curr = sum - nums[n - 1];
        curr -= nums[n - 2];
        if (curr == nums[n - 2])
            for (auto& i : map[nums[n - 1]])
                ans.pb(i);
    }

    {
        int curr = sum - nums[n - 1];
        int need = curr - nums[n - 1];
        if (map.count(need) and need != nums[n - 1])
            for (auto& i : map[need])
                ans.pb(i);
    }

    cout << ans.size() nl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}