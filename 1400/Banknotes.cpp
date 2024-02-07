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

unsigned int binpow(unsigned int a, unsigned int b) {
    unsigned int res = 1;
    while (b > 0) {
        if (b & 1)
            res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n, k; cin >> n >> k;
    k++;

    vi nums(n);
    for (int& a : nums) cin >> a;

    vi ans(19);
    int prev = 0;
    for (int i = 0; i < 19 and k; i++)
        if (binary_search(all(nums), i)) {
            int b = min(9ll, k);
            ans[i] = b;
            k -= b;
            prev = i;
        }
        else {
            int b = min(9 * binpow(10, i - prev), (unsigned int) k);
            ans[prev] += b;
            k -= b;
        }

    unsigned int res = 0;
    for (int i = 0; i < ans.size(); i++)
        res += ((unsigned int) binpow(10, i)) * ans[i];
    cout << res << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}