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
    
    if (is_sorted(all(nums))) {
        cout << 0 nl;
        return;
    }

    if (nums[n - 1] < nums[n - 2]) {
        cout << -1 nl;
        return;
    }

    if (nums[n - 1] < 0) {
        cout << -1 nl;
        return;
    }

    cout << n - 2 nl;
    for (int i = n - 3; i >= 0; i--)
        cout << i + 1 << " " << i + 2 << " " << n nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}