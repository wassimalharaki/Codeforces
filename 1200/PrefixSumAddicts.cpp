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

    vi nums(k);
    for (int i = 0; i < k; i++)
        cin >> nums[i];
    
    if (k == 1) {
        cout << "YES" nl;
        return;
    }

    bool ok = 1;
    for (int i = 0; i < k - 2; i++)
        if (nums[i + 1] - nums[i] > nums[i + 2] - nums[i + 1])
            ok = 0;
    
    if (not ok) {
        cout << "NO" nl;
        return;
    }

    int max = (nums[0] + (nums[0] > 0 ? n - k : 0)) / (n - k + 1);
    cout << (max > nums[1] - nums[0] ? "NO" : "YES") nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}