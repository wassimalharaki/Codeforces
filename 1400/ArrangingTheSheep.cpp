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
    int n; cin >> n;
    string s; cin >> s;


    vi nums;
    for (int i = 0; i < n; i++)
        if (s[i] == '*')
            nums.pb(i);
    int m = nums.size();

    auto f = [&](int a) -> int {
        int ans = 0;
        for (int i = a - 1; i >= 0; i--)
            ans += nums[a] - a + i - nums[i];
        for (int i = a + 1; i < m; i++)
            ans += nums[i] - nums[a] - i + a;
        return ans;
    };

    cout << (m & 1 ? f(m / 2) : min(f(m / 2), f(m / 2 - 1))) << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}