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

vector<int> spf, primes;
void build(int n) {
    spf = vector<int>(n + 1);
    for (int i = 2; i <= n; i++) {
        if (spf[i] == 0) {
            spf[i] = i;
            primes.push_back(i);
        }
        for (int j = 0; i * primes[j] <= n; j++) {
            spf[i * primes[j]] = primes[j];
            if (primes[j] == spf[i])
                break;
        }
    }
}

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

struct small {
    int x = INT_MAX, y = INT_MAX;
    small() {}
    void insert(int z) {
        if (z < x)
            swap(z, x);
        if (z < y)
            swap(z, y);
    }
};

void solve() {
    build(2e5);
    int n; cin >> n;
    v<int> nums(n);
    for (int& a : nums) cin >> a;

    map<int, small> cnt;
    map<int, int> primes_cnt;
    for (int& a : nums) {
        map<int, int> pfz;
        while (a != 1) {
            pfz[spf[a]]++;
            a /= spf[a];
        }
        for (auto& [key, val] : pfz) {
            cnt[key].insert(val);
            primes_cnt[key]++;
        }
    }

    int ans = 1;
    for (auto& [key, val] : cnt)
        if (primes_cnt[key] == n)
            ans *= binpow(key, val.y);
        else if (primes_cnt[key] == n - 1)
            ans *= binpow(key, val.x);
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}