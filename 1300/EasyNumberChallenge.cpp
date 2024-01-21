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

vi spf, primes;
void build(int n) {
    spf = vi(n + 1);
    for (int i = 2; i <= n; i++) {
        if (spf[i] == 0) {
            spf[i] = i;
            primes.pb(i);
        }
        for (int j = 0; i * primes[j] <= n; j++) {
            spf[i * primes[j]] = primes[j];
            if (primes[j] == spf[i])
                break;
        }
    }
}

const int mod = (1 << 30);

int pf(int n) {
    int res = 1;
    while (n != 1) {
        int a = n, c = 0;
        while (n != 1 and n % spf[a] == 0)
            n /= spf[a], c++;
        res = (res * (c + 1)) % mod;
    }
    return res;
}


void solve() {
    build(1e6);
    int a, b, c; cin >> a >> b >> c;

    int ans = 0;
    for (int i = 1; i <= a; i++)
        for (int j = 1; j <= b; j++)
            for (int k = 1; k <= c; k++)
                ans = (ans + pf(i * j * k)) % mod;
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