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

const int mod = 998244353;

using pii = pair<int, int>;
using vi = v<int>;
using vvi = v<vi>;
using vpii = v<pii>;

void solve() {
    int n, k; cin >> n >> k;

    vi nums(n + 1);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        nums[a] = i;
    }

    vi pre;
    for (int i = n; i > n - k; i--)
        pre.pb(nums[i]);
    sort(all(pre));

    cout << (2 * n - k + 1) * k / 2 << " ";
    int prod = 1;
    for (int i = 0; i < pre.size() - 1; i++)
        prod = prod * (pre[i + 1] - pre[i]) % mod;
    cout << prod;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}