#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF LONG_LONG_MAX
#define nl << '\n'
#define v vector
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define mp make_pair
#define F first
#define S second

using pii = pair<int, int>;
using vi = v<int>;
using vvi = v<vi>;
using vpii = v<pii>;

int divisors(int n) {
    int a = 0;
    for (int i = 1; i * i <= n; i++)
        if (n % i == 0)
            a += (n / i == i ? 1 : 2);
    return a;
}

void solve() {
    int n; cin >> n;

    int g = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        g = gcd(g, a);
    }
    cout << divisors(g) nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}