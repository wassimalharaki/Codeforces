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

v<bool> is_prime;
vi primes = {2};
void build(int n) {
    is_prime = v<bool>(n + 1, 1);
    is_prime[0] = is_prime[1] = 0;

    for (int i = 4; i <= n; i += 2) 
        is_prime[i] = 0;

    for (int i = 3; i * i <= n; i += 2)
        if (is_prime[i])
            for (int j = i * i; j <= n; j += i * 2)
                is_prime[j] = 0;

    for (int i = 3; i <= n; i += 2)
        if (is_prime[i])
            primes.pb(i);
}

void solve() {
    int n; cin >> n;

    vi pf;  
    for (int i = 0; i < primes.size(); i++) {
        if (primes[i] * primes[i] > n) break;
        while (n % primes[i] == 0)
            pf.pb(primes[i]), n /= primes[i];
    }
    if (n != 1) pf.pb(n);
    n = pf.size();

    if (n < 3) {
        cout << "NO" nl;
        return;
    }

    int i = 2, a = pf[0], b = pf[1];
    if (b == a)
        b *= pf[i++];

    if (i == n) {
        cout << "NO" nl;
        return;
    }

    int c = 1;
    while (i < n)
        c *= pf[i++];
    
    if (c == a or c == b) {
        cout << "NO" nl;
        return;
    }

    cout << "YES" nl << a << " " << b << " " << c nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    build(1e5);
    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}