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

const int N = 63;
const int mod = 1e9 + 7;

void add(int& a, int b) {
    a = (a + b) % mod;
}

v<v<int>> multiply(v<v<int>>& a, v<v<int>>& b) {
    int n = a.size();
    v c(n, v<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                add(c[i][k], a[i][j] * b[j][k] % mod);
    return c;
}

v<v<int>> matpow(v<v<int>>& a, int b) {
    int n = a.size();
    v res(n, v<int>(n, 1));
    while (b) {
        if (b & 1)
            res = multiply(res, a);
        b >>= 1;
        a = multiply(a, a);
    }
    return res;
}

void solve() {
    int n, k; cin >> n >> k;

    v<int> a(n);
    for (int& x : a) cin >> x;

    v adj(n + 1, v<int>(n + 1));
    for (int i = 0; i < n; i++) {
        adj[i][n] = 1;
        for (int j = i; j < n; j++)
            if (__builtin_popcountll(a[i] ^ a[j]) % 3 == 0)
                adj[i][j] = adj[j][i] = 1;
    }
    cout << matpow(adj, k)[0][n] << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}