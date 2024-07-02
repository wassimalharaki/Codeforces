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

// O(d(n^p))
vector<int> gen_divisors(const vector<array<int, 2>>& pfs) {
    vector<int> divs{1};

    auto f = [&](int x, int i, auto&& f) -> void {
        if (i >= pfs.size()) return;
        f(x, i + 1, f);
        for (int j = 0; j < pfs[i][1]; j++) {
            x *= pfs[i][0];
            divs.push_back(x);
            f(x, i + 1, f);
        }
    };
    f(1, 0, f);

    sort(divs.begin(), divs.end());
    return divs;
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
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    auto check = [&]() {
        int x = c;
        int z = a * b;
        z /= gcd(z, x);
        int y = (b / z + 1) * z;
        if (y > b and y <= d) {
            cout << x << " " << y << nl;
            return 1;
        }
        return 0;
    };
    if (check()) return;


    auto pf_a = prime_factors(a), pf_b = prime_factors(b);
    int i = 0, j = 0;
    v<array<int, 2>> pfs;
    while (i < pf_a.size() and j < pf_b.size())
        if (pf_a[i][0] == pf_b[j][0]) {
            pfs.push_back({pf_a[i][0], pf_a[i][1] + pf_b[j][1]});
            i++, j++;
        }
        else if (pf_a[i][0] < pf_b[j][0])
            pfs.push_back(pf_a[i++]);
        else
            pfs.push_back(pf_b[j++]);
        
    while (i < pf_a.size())
        pfs.push_back(pf_a[i++]);
    while (j < pf_b.size())
        pfs.push_back(pf_b[j++]);

            
    v<int> divs = gen_divisors(pfs);
    for (int& x : divs) {
        if (x > c) break;
        if (x <= a) continue;
        int z = a * b;
        z /= gcd(z, x);
        int y = (b / z + 1) * z;
        if (y > b and y <= d) {
            cout << x << " " << y << nl;
            return;
        }
    }

    for (int& y : divs) {
        if (y > d) break;
        if (y <= b) continue;
        int z = a * b;
        z /= gcd(z, y);
        int x = (a / z + 1) * z;
        if (x > a and x <= c) {
            cout << x << " " << y << nl;
            return;
        }
    }
    cout << "-1 -1" << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}