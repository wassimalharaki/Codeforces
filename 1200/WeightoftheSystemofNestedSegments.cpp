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

    vvi nums(m, vi(3));
    for (int i = 0; i < m; i++)
        cin >> nums[i][1] >> nums[i][0], nums[i][2] = i + 1;
    sort(all(nums));

    vvi use(2 * n, vi(2));
    for (int i = 0; i < 2 * n; i++)
        use[i][0] = nums[i][1],
        use[i][1] = nums[i][2];
    sort(all(use));

    int weight = 0;
    vvi answ(n, vi(2));
    for (int i = 0; i < 2 * n; i++) {
        weight += nums[i][0];
        answ[(i >= n ? 2 * n - i - 1 : i)][i / n] = use[i][1];
    }

    cout << weight nl;
    for (int i = 0; i < n; i++)
        cout << answ[i][0] << " " << answ[i][1] nl;
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