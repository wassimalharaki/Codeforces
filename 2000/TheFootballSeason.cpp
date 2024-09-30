#include <bits/stdc++.h>
using namespace std;
#define int __int128_t
#define nl '\n'
#define v vector

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
bool find_any_sol(int a, int b, int c, int &x0, int &y0) {
    int g = gcd(a, b, x0, y0);
    if (c % g) return 0;
    c /= g, x0 *= c, y0 *= c;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return 1;
}

string ts(int x) {
    string s;
    while (x)
        s.push_back(char('0' + x % 10)), x /= 10;
    reverse(s.begin(), s.end());
    if (s.empty()) s += '0';
    return s;
}

void solve() {
    long long n, p, w, d;
    cin >> n >> p >> w >> d;

    int x, y;
    if (not find_any_sol(w, d, p, x, y))
        cout << -1 << nl;
    else {
        int g = gcd(w, d);
        int cx = d / g, cy = w / g;

        if (x < 0) {
            int k = (- x + cx - 1) / cx;
            x += k * cx;
            y -= k * cy;
        }
        else if (y < 0) {
            int k = (- y + cy - 1) / cy;
            y += k * cy;
            x -= k * cx;
        }

        if (x < 0 or y < 0) {
            cout << -1 << nl;
            return;
        }

        if (cx > cy) {
            int k = x / cx;
            x -= k * cx;
            y += k * cy;
        }
        else if (cy > cx) {
            int k = y / cy;
            y -= k * cy;
            x += k * cx;
        }

        if (x + y > n)
            cout << -1 << nl;
        else
            cout << ts(x) << " " << ts(y) << " " << ts(n - x - y) << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    signed T = 1;
    // cin >> T;
    while (T--) solve();
}