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

    vi ok(n + 1, n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        ok[a]--; ok[b]--;
    }

    cout << n - 1 nl;
    int j = max_element(1 + all(ok)) - ok.begin();
    for (int i = 1; i <= n; i++)
        if (i != j)
            cout << j << " " << i nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}