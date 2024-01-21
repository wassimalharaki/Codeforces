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

vi fact(2e5 + 1);
const int mod = 998244353;

int gcd(int a, int b, int& x, int& y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1;
    while (b) {
        int q = a / b;
        tie(x, x1) = make_pair(x1, x - q * x1);
        tie(y, y1) = make_pair(y1, y - q * y1);
        tie(a, b) = make_pair(b, a - q * b);
    }
    return a;
}

int modinv(int a, int m) {
    int x, y;
    int g = gcd(a, m, x, y);
    return (g == 1 ? (x % m + m) % m : 0);
}

void solve() {
    string s; cin >> s;

    vi times{1};
    for (int i = 1; i < s.size(); i++)
        if (s[i] == s[i - 1])
            times[times.size() - 1]++;
        else
            times.pb(1);
    
    int a = s.size() - times.size(), ans = 1;
    for (int i = 0; i < times.size(); i++)
        ans = ans * fact[times[i]] % mod * modinv(fact[times[i] - 1], mod) % mod;
    ans = (ans * fact[a]) % mod;
    
    cout << a << " " << ans << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fact[0] = 1;
    for (int i = 1; i <= 2e5; i++)
        fact[i] = (fact[i - 1] * i) % mod;

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}