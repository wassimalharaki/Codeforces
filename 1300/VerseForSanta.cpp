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
    int n, k; cin >> n >> k;
    int s = k;

    vi nums(n);
    for (int& a : nums) cin >> a;

    int imax = 0, r;
    for (r = 0; r < n; r++)
        if (s - nums[r] >= 0) {
            if (nums[r] > nums[imax])
                imax = r;
            s -= nums[r];
        }
        else break;
    
    if (r == n) {
        cout << 0 << nl;
        return;
    }

    s = k;
    int a = 0;
    for (int i = 0; i < n; i++)
        if (i == imax) continue;
        else if (s - nums[i] >= 0)
            s -= nums[i], a++;
        else break;
    
    s = k;
    int b = 0;
    for (int i = 0; i < n; i++)
        if (i == r) continue;
        else if (s - nums[i] >= 0)
            s -= nums[i], b++;
        else break;
    
    cout << (a > b ? imax + 1 : r + 1) << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}