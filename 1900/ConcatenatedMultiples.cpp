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

// O(1)
struct splitmix64_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

// O(log(b))
int binpow(int a, int b, const int m) {
    a %= m;
    int res = 1;
    while (b) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n, k; cin >> n >> k;
    const int M = k;

    v<int> a(n);
    for (int& x : a) cin >> x;

    array<unordered_map<int, int, splitmix64_hash>, 11> cnt;
    for (int x : a)
        for (int i = 1; i < 11; i++)
            cnt[i][x = x * 10 % M]++;

    int ans = 0;
    for (int& x : a) {
        int m = to_string(x).size(), y = (M - x % M) % M;
        if (cnt[m].count(y))
            ans += cnt[m][y] - (x * binpow(10, m, M) % M == y);
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