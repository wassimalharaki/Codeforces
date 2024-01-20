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
    for (int& a : nums) cin >> a;

    vi dir(n);
    dir[0] = 1, dir[n - 1] = -1;
    for (int i = 1; i < n - 1; i++) {
        int l = nums[i] - nums[i - 1];
        int r = nums[i + 1] - nums[i];
        dir[i] = (r > l ? -1 : 1);
    }

    vi pr(n), pl(n);
    for (int i = 1; i < n; i++)
        pr[i] = pr[i - 1] + (dir[i - 1] == 1 ? 1 : nums[i] - nums[i - 1]);
    
    for (int i = n - 2; i >= 0; i--)
        pl[i] = pl[i + 1] + (dir[i + 1] == -1 ? 1 : nums[i + 1] - nums[i]);

    int q; cin >> q;
    while (q--) {
        int a, b; cin >> a >> b;
        a--, b--;
        if (b > a)
            cout << pr[b] - pr[a] nl;
        else
            cout << pl[b] - pl[a] nl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}