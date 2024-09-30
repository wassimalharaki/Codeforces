#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

long double PI = 3.141592653589793238462643383279502884L;

void solve() {
    int n; cin >> n;
    n <<= 1;

    cout << fixed << setprecision(9)
         << sqrt(1 + pow(tan(PI / 2 - PI / n), 2)) * cos(PI / (2 * n)) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}