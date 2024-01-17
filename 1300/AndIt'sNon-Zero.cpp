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

vvi prefix(2e5 + 1, vi(31));

void solve() {
    int l, r; cin >> l >> r;

    vi bits(31);
    for (int i = 0; i < 31; i++)
        bits[i] = prefix[r][i] - prefix[l - 1][i];
    cout << r - l + 1 - *max_element(all(bits)) nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 1; i <= 2e5; i++)
        for (int j = 0; j < 31; j++)
            prefix[i][j] = prefix[i - 1][j] + ((i & (1 << j)) != 0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}