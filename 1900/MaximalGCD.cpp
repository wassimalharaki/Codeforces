#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

// O(Nlog(log(N)))
const int N = 1e5 + 1;
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
        if (i >= (int) pfs.size()) return;
        f(x, i + 1, f);
        for (int j = 0; j < pfs[i][1]; j++) {
            x *= pfs[i][0];
            divs.push_back(x);
            f(x, i + 1, f);
        }
    };
    f(1, 0, f);

    sort(divs.rbegin(), divs.rend());
    return divs;
}

// O(sqrt(n) / log(sqrt(n)) + d(n^p))
vector<int> divisors(int n, int p = 1) {
    if (primes.empty()) build();

    vector<array<int, 2>> pfs;
    for (const int& x : primes) {
        if (x * x > n) break;
        if (n % x) continue;
        pfs.push_back({x, 0});
        while (n % x == 0) {
            n /= x;
            pfs.back()[1] += p;
        } 
    }
    if (n != 1) pfs.push_back({n, p});
    
    return gen_divisors(pfs);
}

int mul(int x, int y) {
    if (y >= LLONG_MAX / x)
        return LLONG_MAX;
    return x * y;
}

void solve() {
    int n, k; cin >> n >> k;

    if (k >= 2e5) {
        cout << -1 << nl;
        return;
    }

    for (int& d : divisors(n)) {
        int x = mul(d, k * (k - 1) / 2);
        if (x > n) continue;
        if (n - x <= d * (k - 1)) continue;
        if (gcd(n - x, d) != d) continue;
        for (int i = 1; i < k; i++)
            cout << i * d << " ";
        cout << n - x << nl;
        return;
    }
    cout << -1 << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}