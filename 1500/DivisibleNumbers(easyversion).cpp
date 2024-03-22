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

vector<int> divisors(int n) {
    vector<int> divs;

    for (int i = 1; i * i <= n; i++)
        if (n % i == 0)
            divs.push_back(i);

    for (int i = divs.size() - 1; i >= 0; i--)
        if (n / divs[i] != divs[i])
            divs.push_back(n / divs[i]);

    return divs;
}

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    auto check = [&]() {
        int x = c;
        int z = a * b;
        z /= __gcd(z, x);
        int y = (b / z + 1) * z;
        if (y > b and y <= d) {
            cout << x << " " << y << nl;
            return 1;
        }
        return 0;
    };
    if (check()) return;

    v<int> div_a = divisors(a);
    v<int> div_b = divisors(b);

    set<int> divs;
    for (int& x : div_a)
        for (int& y : div_b)
            divs.insert(x * y);
            
    for (int x : divs) {
        if (x > c) break;
        if (x <= a) continue;
        int z = a * b;
        z /= __gcd(z, x);
        int y = (b / z + 1) * z;
        if (y > b and y <= d) {
            cout << x << " " << y << nl;
            return;
        }
    }

    for (int y : divs) {
        if (y > d) break;
        if (y <= b) continue;
        int z = a * b;
        z /= __gcd(z, y);
        int x = (a / z + 1) * z;
        if (x > a and x <= c) {
            cout << x << " " << y << nl;
            return;
        }
    }
    cout << "-1 -1" << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}