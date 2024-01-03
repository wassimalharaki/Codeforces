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

    int sum1 = 0, sum2 = 0;
    bool ok = 0;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        sum1 += a;
        sum2 += b;
        if ((a ^ b) & 1) ok = 1;
    }

    if (!(sum1 & 1) and !(sum2 & 1))
        cout << 0;
    else if ((sum1 ^ sum2) & 1)
        cout << -1;
    else if ((sum1 & 1) and (sum2 & 1) and ok)
        cout << 1;
    else
        cout << -1;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}