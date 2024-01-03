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
    
    vi awake(n);
    int max = 0;
    for (int i = 0; i < n; i++) {
        cin >> awake[i];
        max += (awake[i] ? nums[i] : 0);
    }
    
    int curr = max, add = 0;
    for (int i = 0; i < k; i++)
        add += (not awake[i] ? nums[i] : 0);
    max += add;
    for (int i = k; i < n; i++) {
        add -= (not awake[i - k] ? nums[i - k] : 0);
        add += (not awake[i] ? nums[i] : 0);
        max = std::max(max, curr + add);
    }
    cout << max nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}