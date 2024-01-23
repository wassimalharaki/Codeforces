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
    int n, m; cin >> n >> m;

    vvi nums(n, vi(m));
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++)
            nums[i][j] = s[j] - '0';
    }

    if (nums[0][0]) {
        cout << -1 << nl;
        return;
    }

    vvi ops;
    for (int i = n - 1; i >= 0; i--)
        for (int j = m - 1; j >= 0; j--)
            if (nums[i][j]) {
                if (j)
                    ops.pb(vi{i + 1, j, i + 1, j + 1});
                else
                    ops.pb(vi{i, j + 1, i + 1, j + 1});
            }
    cout << ops.size() << nl;
    for (vi& i : ops) {
        for (int j : i)
            cout << j << " ";
        cout << nl;
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