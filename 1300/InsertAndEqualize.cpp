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
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    sort(all(nums));

    if (n == 1) {
        cout << 1 nl;
        return;
    }

    int x = 0;
    for (int i = 0; i < n - 1; i++)
        x = gcd(x, nums[i + 1] - nums[i]);
    
    int y = nums[n - 1] + x;
    for (int i = n - 2; i >= 0; i--)
        if ((nums[i + 1] - nums[i]) / x != 1) {
            y = nums[i + 1] - x;
            break;
        }
    
    if (y < nums[n - 1])
        swap(nums[n - 1], y);
    int ops = (y - nums[n - 1]) / x;
    for (int i = 0; i < n - 1; i++)
        ops += (y - nums[i]) / x;
    cout << ops nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}