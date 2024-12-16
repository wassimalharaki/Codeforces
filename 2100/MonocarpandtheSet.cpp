#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

const int mod = 998244353;

// O(log(min(a, b)))
int gcd(int a, int b, int& x, int& y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1;
    while (b) {
        int q = a / b;
        tie(x, x1) = make_pair(x1, x - q * x1);
        tie(y, y1) = make_pair(y1, y - q * y1);
        tie(a, b) = make_pair(b, a - q * b);
    }
    return a;
}

// O(log(min(a, b)))
int modinv(int a, const int m = mod) {
    int x, y;
    int g = gcd(a, m, x, y);
    return (g == 1 ? (x % m + m) % m : 0);
}

void solve() {
    int n, m; cin >> n >> m;
    string s; cin >> s;

    int ans = 1;
    for (int i = 1; i < n; i++)
        if (s[i] == '?')
            ans = ans * i % mod;

    cout << (s[0] == '?' ? 0 : ans) << nl;
    while (m--) {
        int i; cin >> i; i--;
        char c; cin >> c;
        if (c == '?' and s[i] != '?' and i)
            ans = ans * i % mod;
        if (c != '?' and s[i] == '?' and i)
            ans = ans * modinv(i) % mod;
        s[i] = c;
        cout << (s[0] == '?' ? 0 : ans) << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}