#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

// O(Nlog(log(N)))
const int N = 1e6 + 1;
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
    int n; cin >> n;

    v<int> a(n);
    for (int& x : a) cin >> x;

    int sum = accumulate(a.begin(), a.end(), 0ll);
    if (sum == 1) return void(cout << -1 << nl);

    int ans = LLONG_MAX;
    v<int> b, suff(n + 1), pref(n + 1);
    for (auto& [p, _] : prime_factors(sum)) {
        int curr = 0, carry = 0;
        for (int i = 0; i < n; i++) {
            carry = (a[i] + carry) % p;
            b.push_back(a[i]);
            if (carry) continue;

            int m = b.size(), x = 0;
            for (int j = 0; j < m; j++) {
                int y = (x + b[j]) % p;
                y = min(y, p - y);
                x = (x + b[j]) % p;
                pref[j + 1] = pref[j] + y;
            }
            x = 0, suff[m] = 0;
            for (int j = m - 1; j >= 0; j--) {
                int y = (x + b[j]) % p;
                y = min(y, p - y);
                x = (x + b[j]) % p;
                suff[j] = suff[j + 1] + y;
            }
            x = suff[0];
            for (int j = 0; j < m; j++)
                x = min(x, pref[j] + suff[j + 1]);
            curr += x;
            b.clear();
        }
        ans = min(ans, curr);
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}