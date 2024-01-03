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

struct Sieve {
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
} sieve;

void solve() {
    int n; cin >> n;
    
    if (n == 1) {
        cout << 1 nl << 1;
        return;
    }

    if (n == 2) {
        cout << 1 nl << "1 1";
        return;
    }

    sieve.build(n + 1);
    cout << 2 nl;
    for (int i = 2; i < n + 2; i++)
        cout << (sieve.is_prime[i] ? 1 : 2) << " ";
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}