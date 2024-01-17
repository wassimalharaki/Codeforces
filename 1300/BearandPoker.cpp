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
    sort(rall(nums));

    for (int i = 0; i < n - 1; i++) {
        int lcm = std::lcm(nums[i], nums[i + 1]);
        int a = lcm / nums[i], b = lcm / nums[i + 1];
        while (a % 3 == 0) a /= 3;
        while (a % 2 == 0) a /= 2;
        while (b % 3 == 0) b /= 3;
        while (b % 2 == 0) b /= 2;
        if (a > 1 or b > 1) {
            cout << "No" nl;
            return;
        }
    }
    cout << "Yes" nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}