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

    int ops = 0;
    for (int i = 0; i < n / 2; i++) {
        int a = n - i - 1;
        for (int j = 0; j < a - i; j++) {
            vi four{
                nums[i][i + j],
                nums[i + j][a],
                nums[a][a - j],
                nums[a - j][i],
            };

            int zeroes = count(all(four), 0ll);
            int ones = count(all(four), 1ll);
            ops += 4 - max(zeroes, ones);
        }
    }
    cout << ops nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}