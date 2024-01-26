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
    int n, s; cin >> n >> s;

    int ones = n - 1;
    int big = s - (n - 1);
    int small = (ones + 1) / 2;

    int ok = -1;
    for (int i = small + 1; i < big; i++) {
        if (s - i >= big) continue;
        if (s - i <= small) continue;
        ok = i;
        break;
    }

    if (ok == -1) {
        cout << "NO";
        return;
    }

    vi ans;
    for (int i = 0; i < ones / 2; i++)
        ans.pb(1);
    ans.pb(big);
    for (int i = 0; i < (ones + 1) / 2; i++)
        ans.pb(1);

    cout << "YES" << nl;
    for (int& i : ans)
        cout << i << " ";
    cout << nl << ok;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}