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
    int n, k; cin >> n >> k;

    vi nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    
    int lo = 0, hi = 1e18, answ;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        bool ok = 1;
        int sum = nums[0] + mid;
        for (int i = 1; i < n; sum += nums[i], i++)
            if ((nums[i] * 100 + sum - 1) / sum > k)
                ok = 0;
        
        if (ok)
            answ = mid, hi = mid - 1;
        else
            lo = mid + 1;
    }
    cout << answ nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}