#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector
#define all(v) v.begin(), v.end()

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

vector<bool> is_prime;
vector<int> primes = {2};
void build(int n) {
    is_prime = vector<bool>(n + 1, 1);
    is_prime[0] = is_prime[1] = 0;

    for (int i = 4; i <= n; i += 2) 
        is_prime[i] = 0;

    for (int i = 3; i * i <= n; i += 2)
        if (is_prime[i])
            for (int j = i * i; j <= n; j += i * 2)
                is_prime[j] = 0;

    for (int i = 3; i <= n; i += 2)
        if (is_prime[i])
            primes.push_back(i);
}

void solve() {
    int n; cin >> n;

    v<int> ans;
    for (int p : primes) {
        int q = p;
        while (p <= n) {
            ans.push_back(p);
            p *= q;
        }
    }
    
    cout << ans.size() << nl;
    for (int& a : ans)
        cout << a << " ";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    build(1e3);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}