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

    vvi nums(n, vi(m));
    int ones = 0;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            nums[i][j] = (s[j] == '1');
            if (nums[i][j]) ones++;
        }
    }
    
    if (ones == n * m) {
        cout << n * m - 2 nl;
        return;
    }

    if (ones == 0) {
        cout << 0 nl;
        return;
    }

    bool ok = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < m - 1; j++) {
            vi a{
                nums[i][j],
                nums[i][j + 1],
                nums[i + 1][j],
                nums[i + 1][j + 1]
            };

            int zero = count(all(a), 0ll);
            int one = count(all(a), 1ll);
            if (zero >= 2 and one)
                ok = 1;
        }
    cout << (ok ? ones : ones - 1) nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}