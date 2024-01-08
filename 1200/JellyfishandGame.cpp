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
    int n, m, k; cin >> n >> m >> k;

    vi a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    sort(all(a)); sort(all(b));
    int j = accumulate(all(a), 0ll);
    int g = accumulate(all(a), 0ll);

    if (b[m - 1] > a[0])
        j += b[m - 1] - a[0];
    
    if (k == 1) {
        cout << j nl;
        return;
    }

    int val = max(a[n - 1], b[m - 1]) - min(a[0], b[0]);
    cout << (k & 1 ? j : j - val) nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}