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

// O(sqrt(n) / log(sqrt(n)))
bool is_p(int n) {
    if (primes.empty()) build();

    int cnt = 0;
    for (const int& x : primes) {
        if (x * x > n) break;
        if (n % x) continue;
        while (n % x == 0) {
            n /= x;
            cnt++;
        } 
    }
    if (n != 1) cnt++;
    
    return cnt == 1;
}

void solve() {
    int n; cin >> n;

    if (is_p(n)) {
        cout << "1\n" << n;
        return;
    }

    int m = n - 2;
    while (not is_p(m)) m--;
    n -= m;

    v<int> ans{m};
    for (int& p : primes)
        if (n == p) {
            ans.push_back(p);
            break;
        }
        else if (is_prime[n - p]) {
            ans.push_back(p);
            ans.push_back(n - p);
            break;
        }
    
    cout << ans.size() << nl;
    for (int& p : ans)
        cout << p << " ";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}