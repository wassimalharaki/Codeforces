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
    int n, d; cin >> n >> d;

    vi nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    
    int answ = 0;
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(all(nums), nums[i] + d);
        if (it == nums.end() or *it != nums[i] + d)
            --it;
        int p = it - nums.begin() - i;
        answ += p * (p - 1) / 2;
    }
    cout << answ;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}