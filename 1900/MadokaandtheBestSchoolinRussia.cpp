#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

// O(Nlog(log(N)))
const int N = 4e4 + 1;
bitset<N> is_prime;
vector<int> primes;
void build() {
    is_prime.set();
    is_prime[0] = is_prime[1] = 0;

    primes.push_back(2);
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

// O(sqrt(n) / log(sqrt(n)))
vector<array<int, 2>> prime_factors(int n) {
    if (primes.empty()) build();

    vector<array<int, 2>> pfs;
    for (const int& x : primes) {
        if (x * x > n) break;
        if (n % x) continue;
        pfs.push_back({x, 0});
        while (n % x == 0) {
            n /= x;
            pfs.back()[1]++;
        }
    }
    if (n != 1) pfs.push_back({n, 1});
    
    return pfs;
}

void solve() {
    int x, d; cin >> x >> d;

    int p = 0;
    while (x % d == 0)
        x /= d, p++;

    int others = 0;
    for (auto& [x, y] : prime_factors(x))
        others += y;

    if (p <= 1) {
        cout << "NO" << nl;
        return;
    }
    
    if (p == 2) {
        cout << (others > 1 ? "YES" : "NO") << nl;
        return;
    }

    if (others > 1) {
        cout << "YES" << nl;
        return;
    }

    auto pfs = prime_factors(d);
    if (pfs.size() > 1) {
        cout << "YES" << nl;
        return;
    }
    
    if (pfs[0][1] == 1) {
        cout << "NO" << nl;
        return;
    }

    if (others == 0) {
        cout << "YES" << nl;
        return;
    }

    others = prime_factors(x)[0][0];
    if (others != pfs[0][0]) {
        cout << "YES" << nl;
        return;
    }

    if (pfs[0][1] > 2) {
        cout << "YES" << nl;
        return;
    }

    if (p > 3) {
        cout << "YES" << nl;
        return;
    }

    cout << (pfs[0][1] > 2 ? "YES" : "NO") << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}