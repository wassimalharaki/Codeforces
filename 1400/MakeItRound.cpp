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
    int n, m; cin >> n >> m;
    int twos = 0, fives = 0;
    int a = n;
    while (!(a & 1))
        twos++, a >>= 1;
    while (!(a % 5))
        fives++, a /= 5;

    int b = 1;
    while (fives > twos and (b << 1) <= m)
        b <<= 1, twos++;
    while (twos > fives and b * 5 <= m)
        b *= 5, fives++;
    while (b * 10 <= m)
        b *= 10;
    
    for (int i = 9; i >= 2; i--)
        if (b * i <= m)
            b *= i;
    
    cout << b * n << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}