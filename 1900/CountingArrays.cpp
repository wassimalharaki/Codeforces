#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

// O(Nlog(log(N)))
const int N = 37;
bitset<N> is_prime;
vector<int> primes{2};
void build() {
    is_prime.set();
    is_prime[0] = is_prime[1] = 0;

    for (int i = 4; i < N; i += 2) 
        is_prime[i] = 0;

    for (int i = 3; i * i < N; i += 2)
        if (is_prime[i])
            for (int j = i * i; j < N; j += i * 2)
                is_prime[j] = 0;

    for (int i = 3; i < N; i += 2)
        if (is_prime[i])
            primes.push_back(i);
}

const int mod = 998244353;

void add(int& a, int b) {
    a = (a + b) % mod;
}

void solve() {
    int n, m; cin >> n >> m;

    int ans = 0, tot = 1;
    for (int i = 1; i <= n; i++) {
        tot = tot * (m % mod) % mod;
        if (i > 36)
            add(ans, tot);
        else {
            int bad = 1, x = 1;
            for (int j = 1; j <= i; j++) {
                if (is_prime[j]) x *= j;
                bad = bad * ((m / x) % mod) % mod;
            }
            add(ans, tot - bad);
        }
    }
    cout << (ans + mod) % mod << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    build();
    int T = 1;
    // cin >> T;
    while (T--) solve();
}