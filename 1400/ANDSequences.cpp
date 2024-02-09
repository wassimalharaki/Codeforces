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

const int mod = 1e9 + 7;
vi fact(2e5 + 1);

void solve() {
    int n; cin >> n;

    vi nums(n);
    for (int& a : nums) cin >> a;

    int a = accumulate(all(nums), (1ll << 60) - 1, [](int x, int y) {
        return x & y;
    });
    int b = count(all(nums), a);
    
    cout << b * (b - 1) % mod * fact[n - 2] % mod << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fact[0] = fact[1] = 1;
    for (int i = 2; i < 2e5 + 1; i++)
        fact[i] = i * fact[i - 1] % mod;

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}