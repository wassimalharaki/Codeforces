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
    int n, m; cin >> n >> m;
    string s; cin >> s;

    vi nums(m);
    for (int& a : nums) cin >> a;
    nums.pb(n); m++;

    vvi prefix(n + 1, vi(26));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 26; j++)
            prefix[i + 1][j] = prefix[i][j] + (s[i] - 'a' == j);
    
    vi ans(26);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < 26; j++)
            ans[j] += prefix[nums[i]][j];
    for (int i = 0; i < 26; i++)
        cout << ans[i] << " ";
    cout nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}