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

void solve() {
    int n, m; cin >> n >> m;
    cout << (spf[n] <= m and n != 1 ? "NO" : "YES") << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    build(1e6);
    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}