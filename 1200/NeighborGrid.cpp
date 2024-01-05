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

    vvi nums(n, vi(m)); bool ok = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> nums[i][j];
            if (nums[i][j] > 4)
                ok = 0;
        }

    if (nums[0][0] > 2) ok = 0;
    if (nums[n - 1][0] > 2) ok = 0;
    if (nums[0][m - 1] > 2) ok = 0;
    if (nums[n - 1][m - 1] > 2) ok = 0;

    for (int i : {0ll, n - 1})
        for (int j = 0; j < m; j++)
            if (nums[i][j] > 3)
                ok = 0;
    
    for (int j : {0ll, m - 1})
        for (int i = 0; i < n; i++)
            if (nums[i][j] > 3)
                ok = 0;
    
    if (not ok) {
        cout << "NO" nl;
        return;
    }
    cout << "YES" nl;
    
    vi dx{0, -1, 0, 1};
    vi dy{1, 0, -1, 0};
    auto is_valid = [&](int i, int j) {
        return i >= 0 and j >= 0 and i < n and j < m;
    };
    auto count = [&](int i, int j) {
        int c = 0;
        for (int k = 0; k < 4; k++)
            if (is_valid(i + dx[k], j + dy[k]))
                c++;
        return c;
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << count(i, j) << " ";
        cout nl;
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