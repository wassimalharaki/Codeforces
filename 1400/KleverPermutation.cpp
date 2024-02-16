#include <bits/stdc++.h>

using namespace std;

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

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
    int n, k; cin >> n >> k;

    int l = 1, r = n;
    vi ans(n);
    for (int i = 0; i < n; i++) {
        if (ans[i] != 0) continue;
        if (!(i & 1)) {
            ans[i] = l++;
            for (int j = i + k; j < n; j += k)
                ans[j] = l++;
        }
        else {
            ans[i] = r--;
            for (int j = i + k; j < n; j += k)
                ans[j] = r--;
        }
    }
    for (int& a : ans)
        cout << a << " ";
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}