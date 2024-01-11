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

    vvi nums(n, vi(n));
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < n; j++)
            nums[i][j] = (s[j] == '1');
    }

    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1; j++)
            if (nums[i][j] == 1 and nums[i + 1][j] != 1 and nums[i][j + 1] != 1) {
                cout << "NO" nl;
                return;
            }
    cout << "YES" nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}