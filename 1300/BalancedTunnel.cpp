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

    vi a(n), b(n);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;
    reverse(all(a)); reverse(all(b));

    vi pos(n + 1);
    for (int i = 0; i < n; i++)
        pos[b[i]] = i;

    int look = a[n - 1], ans = 0;
    for (int i = n - 2; i >= 0; i--)
        if (pos[a[i]] < pos[look])
            look = a[i];
        else
            ans++;
    cout << ans;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}