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

    vi diamonds(n), miners(n);
    int i = 0, j = 0;
    for (int k = 0; k < 2 * n; k++) {
        int x, y; cin >> x >> y;
        x ? diamonds[i++] = abs(x) : miners[j++] = abs(y);
    }
    sort(all(diamonds)); sort(all(miners));

    long double answ = 0;
    for (i = 0; i < n; i++)
        answ += sqrt(diamonds[i] * diamonds[i] + miners[i] * miners[i]);
    cout << fixed << setprecision(15) << answ nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}