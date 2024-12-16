#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

#define double long double

struct point {
    double x, y;

    point() {}
    point(double _x, double _y) {
        x = _x, y = _y;
    }

    friend istream& operator>>(istream& in, point& p) {
        in >> p.x >> p.y;
        return in;
    }
};

const double eps = 1e-4;
const double pi = numbers::pi_v<double>;

double gcd(double x, double y) {
    return fabs(y) < eps ? x : gcd(y, fmod(x, y));
}

void solve() {
    array<point, 3> p;
    for (auto& q : p) cin >> q;

    auto sqr = [&](double x) -> double {
        return x * x;
    };

    auto dist = [&](point& p1, point& p2) -> double {
        return sqrtl(sqr(p1.x - p2.x) + sqr(p1.y - p2.y));
    };

    double a = dist(p[0], p[1]);
    double b = dist(p[0], p[2]);
    double c = dist(p[1], p[2]);
    double x = (a + b + c) / 2;
    double ta = sqrtl(x * (x - a) * (x - b) * (x - c));
    double r = a * b * c / (4 * ta);
    double A = acosl((sqr(b) + sqr(c) - sqr(a)) / (2 * b * c));
    double B = acosl((sqr(a) + sqr(c) - sqr(b)) / (2 * a * c));
    double C = acosl((sqr(a) + sqr(b) - sqr(c)) / (2 * a * b));

    double ans = 1e18;
    if (abs(A - B) < eps and abs(B - C) < eps)
        ans = ta;

    double n = pi / gcd(gcd(A, B), C);
    ans = min(ans, n * r * r * sin(2 * pi / n) / 2);

    cout << fixed << setprecision(15) << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}