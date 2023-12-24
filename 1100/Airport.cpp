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

void solve() {
    int n, m; cin >> n >> m;
    swap(n, m);

    vi nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    sort(all(nums));

    int min = 0;
    int o = m;
    for (int i = 0; i < n; i++) {
        if (m >= nums[i]) {
            min += (1 + nums[i]) * nums[i] / 2;
            m -= nums[i];
        }
        else {
            min += m * (nums[i] + (nums[i] - m + 1)) / 2;
            break;
        }
    }
    m = o;
    reverse(all(nums));

    int max = 0;
    while (m--) {
        for (int i = 0; i < n; i++)
            if (i == n - 1)
                max += nums[i], nums[i]--;
            else if (nums[i] > nums[i + 1]) {
                max += nums[i], nums[i]--;
                break;
            }
    }
    cout << max << " " << min nl;
}

int32_t main() {
    fast;

    int T = 1;
    // cin >> T;

    while(T--)
        solve();

    return 0;
}