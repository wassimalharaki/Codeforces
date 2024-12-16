#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

// O(N)
const int N = 1e7 + 1;
vector<int> spf(N), primes, ind(N);
void build() {
    for (int i = 2; i < N; i++) {
        if (spf[i] == 0) {
            spf[i] = i;
            primes.push_back(i);
            ind[i] = primes.size();
        }
        for (int j = 0; i * primes[j] < N; j++) {
            spf[i * primes[j]] = primes[j];
            if (primes[j] == spf[i])
                break;
        }
    }
}

void solve() {
    int n; cin >> n;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        sum ^= ind[spf[x]];
    }
    cout << (sum ? "Alice" : "Bob") << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    build();
    ind[spf[1] = 1] = 1;
    ind[2] = 0;
    int T = 1;
    cin >> T;
    while (T--) solve();
}