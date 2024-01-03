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

    vi nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    
    vi p(m);
    for (int i = 0; i < m; i++)
        cin >> p[i];
    sort(all(p));

    int j = p[0] - 1;
    for (int i = 0; i < m - 1; i++)
        if (p[i + 1] - p[i] != 1)
            sort(nums.begin() + j, nums.begin() + p[i] + 1), j = p[i + 1] - 1;
    sort(nums.begin() + j, nums.begin() + p[m - 1] + 1);
    cout << (is_sorted(all(nums)) ? "YES" : "NO") nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}