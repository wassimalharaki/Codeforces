#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define nl << '\n'
#define pii pair<int, int>
#define v vector
#define vi v<int>
#define vvi v<vi>
#define vpii v<pii>
#define mp make_pair
#define pb push_back
#define INF LONG_LONG_MAX
#define F first
#define S second

const int mod = 1e9 + 7;

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

int modinv(int a, int m) {
    int x, y;
    int g = gcd(a, m, x, y);
    return (g == 1 ? (x % m + m) % m : 0);
}

void solve() {
    int n; cin >> n;
    int answ = n * (n + 1) % mod * (2 * n + 1) % mod * modinv(6, mod) % mod;
    answ += (n - 1) * n % mod * (n + 1) % mod * modinv(3, mod) % mod;
    cout << (answ * 2022) % mod nl;
}

int32_t main() {
    fast;

    int T = 1;
    cin >> T;

    while(T--)
        solve();

    return 0;
}