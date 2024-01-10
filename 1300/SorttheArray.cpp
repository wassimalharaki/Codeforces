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
    
    int l = 0, r = 1;
    for (int i = 0; i < n - 1; i++) {
        l = i, r = i + 1;
        while (r < n and nums[r] < nums[r - 1])
            r++;
        if (r > i + 1) {
            reverse(nums.begin() + l, nums.begin() + r);
            break;
        }
    }

    if (is_sorted(all(nums)))
        cout << "yes" nl << l + 1 << " " << r nl;
    else
        cout << "no" nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}