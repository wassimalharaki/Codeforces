#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

// O(Nlog(log(N)))
const int N = 4e4;
bitset<N + 1> is_prime;
vector<int> primes;
void build() {
    is_prime.set();
    is_prime[0] = is_prime[1] = 0;

    primes.push_back(2);
    for (int i = 4; i <= N; i += 2) 
        is_prime[i] = 0;

    for (int i = 3; i * i <= N; i += 2)
        if (is_prime[i])
            for (int j = i * i; j <= N; j += i * 2)
                is_prime[j] = 0;

    for (int i = 3; i <= N; i += 2)
        if (is_prime[i])
            primes.push_back(i);
}

// O(sqrt(n) / log(sqrt(n)))
int prime_factors(int n) {
    if (primes.empty()) build();

    int cnt = 0;
    for (const int& x : primes) {
        if (x * x > n) break;
        while (n % x == 0)
            n /= x, cnt++;
    }

    return cnt + (n != 1);
}

void solve() {
    int a, b, k; cin >> a >> b >> k;
 
    if (k == 1) {
        if (a == b)
            cout << "NO" << nl;
        else if (a % b == 0 or b % a == 0)
            cout << "YES" << nl;
        else
            cout << "NO" << nl;
    }
    else if (k == 2) {
        if (a == 1) {
            if (b == 1)
                cout << "NO" << nl;
            else
                cout << (prime_factors(b) > 1 ? "YES" : "NO") << nl;
        }
        else if (b == 1)
            cout << (prime_factors(a) > 1 ? "YES" : "NO") << nl;
        else
            cout << "YES" << nl;
    }
    else {
        int steps = prime_factors(a) + prime_factors(b);
        cout << (steps >= k ? "YES" : "NO") << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}