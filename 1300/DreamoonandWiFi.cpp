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

vi fact{
    1,
    1,
    2,
    6,
    24,
    120,
    720,
    5040,
    40320,
    362880,
    3628800
};

double binpow(double a, int b) {
    double res = 1;
    while (b > 0) {
        if (b & 1)
            res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

void solve() {
    string s, t; cin >> s >> t;

    int x = count(all(s), '+') - count(all(s), '-');
    int o = count(all(t), '+') - count(all(t), '-');
    int k = count(all(t), '?');
    int diff = abs(x - o);

    if (diff > k or (diff ^ k) & 1) {
        cout << 0.0;
        return;
    }
    int a = (k + diff) / 2, b = a - diff;
    cout << binpow(0.5, k) * fact[k] / (fact[a] * fact[b]);
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    cout << fixed << setprecision(12);
    while (T--) solve();

    return 0;
}