#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

using hi = double;
#define double __float128
const double PI = 3.141592653589793238462643383279502884L;
const double eps = 1e-9;

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct point {
    typedef point P;
    T x, y;
    point(T _x = 0, T _y = 0) : x(_x), y(_y) {}
    bool operator<(P p) const { return tie(x, y) < tie(p.x, p.y); }
    bool operator==(P p) { return tie(x, y) == tie(p.x, p.y); }
    P operator+(P p) { return P(x + p.x, y + p.y); }
    P operator-(P p) { return P(x - p.x, y - p.y); }
    P operator*(T d) { return P(x * d, y * d); }
    P operator/(T d) { return P(x / d, y / d); }
    T dot(P p) { return x * p.x + y * p.y; }
    T cross(P p) { return x * p.y - y * p.x; }
    T cross(P a, P b) { return (a - *this).cross(b - *this); }
    T dist2() { return x * x + y * y; }
    double dist() { return sqrtl((double) dist2()); }
    double angle() { return atan2l(y, x); }
    P unit() { return *this / dist(); }
    P perp() { return P(- y, x); }
    P normal() { return perp().unit(); }
    P rotate(double a) {
        return P(x * cosl(a) - y * sinl(a), x * sinl(a) + y * cosl(a));
    }
    // friend ostream& operator<<(ostream& os, P p) {
    //     return os << fixed << setprecision(20) << "(" << p.x << ", " << p.y << ")";
    // }
};
using P = point<double>;

double seg_dist(P& s, P& e, P& p) {
    if (s == e)
        return (p - s).dist();
    auto d = (e - s).dist2(), t = min(d, max((double) .0, (p - s).dot(e - s)));
    return ((p - s) * d - (e - s) * t).dist() / d;
}

bool on_seg(P s, P e, P p) {
    return seg_dist(s, e, p) <= eps;
}

vector<P> seg_inter(P a, P b, P c, P d) {
    auto oa = c.cross(d, a), ob = c.cross(d, b),
    oc = a.cross(b, c), od = a.cross(b, d);
    if (sgn(oa) * sgn(ob) < 0 and sgn(oc) * sgn(od) < 0)
        return {(a * ob - b * oa) / (ob - oa)};

    set<P> s;
    if (on_seg(c, d, a)) s.insert(a);
    if (on_seg(c, d, b)) s.insert(b);
    if (on_seg(a, b, c)) s.insert(c);
    if (on_seg(a, b, d)) s.insert(d);
    return {s.begin(), s.end()};
}

struct circle {
    int x, y, r;
    double x2, y2, r2;
    friend istream& operator>>(istream& in, circle& c) {
        cin >> c.x >> c.y >> c.r;
        tie(c.x2, c.y2, c.r2) = make_tuple(
            c.x * c.x,
            c.y * c.y,
            c.r * c.r
        );
        return in;
    }
    double area() { return PI * r * r; }

    // friend ostream& operator<<(ostream& os, circle c) {
    //     return os << "(" << c.x << ", " << c.y << ", " << c.r << ")";
    // }
};

double dist(array<int, 2> l, array<int, 2> r) {
    return sqrtl(
        (double)
        ((l[0] - r[0]) * (l[0] - r[0]) +
        (l[1] - r[1]) * (l[1] - r[1]))
    );
}

int dist2(array<int, 2> l, array<int, 2> r) {
    return (l[0] - r[0]) * (l[0] - r[0]) +
        (l[1] - r[1]) * (l[1] - r[1]);
}

double angle(P p1, P p2, P p3) {
    return (p3 - p1).angle() - (p2 - p1).angle();
}

// {minor, major}
array<double, 2> circle_segments(circle& c, P& p1, P& p2) {
    double a = angle(P(c.x, c.y), p1, p2);
    while (a < 0) a += 2 * PI;
    while (a >= 2 * PI) a -= 2 * PI;
    if (a >= PI) a = 2 * PI - a;
    array<double, 2> ans;
    ans[0] = (double) c.r2 * a / 2 - (double) c.r2 * sinl(a) / 2;
    ans[1] = c.area() - ans[0];

    return ans;
}

void solve() {
    circle c1, c2;
    cin >> c1 >> c2;

    if (c2.r > c1.r)
        swap(c1, c2);

    double d = dist({c1.x, c1.y}, {c2.x, c2.y});
    if (d >= c1.r + c2.r) {
        cout << fixed << setprecision(25) << 0. << nl;
        return;
    }

    if (d + c2.r <= c1.r) {
        cout << fixed << setprecision(25) << hi(c2.area()) << nl;
        return;
    }

    double l = (c1.r2 - c2.r2 + d * d) / (double) (2 * d);
    double h = sqrtl(- l * l + c1.r2);
    P p1(
        l / d * (c2.x - c1.x) + h / d * (c2.y - c1.y) + c1.x,
        l / d * (c2.y - c1.y) - h / d * (c2.x - c1.x) + c1.y
    );
    P p2(
        l / d * (c2.x - c1.x) - h / d * (c2.y - c1.y) + c1.x,
        l / d * (c2.y - c1.y) + h / d * (c2.x - c1.x) + c1.y
    );

    double area = circle_segments(c1, p1, p2)[0];
    if (seg_inter(P(c1.x, c1.y), P(c2.x, c2.y), p1, p2).size())
        area += circle_segments(c2, p1, p2)[0];
    else
        area += circle_segments(c2, p1, p2)[1];
    cout << fixed << setprecision(25) << hi(area) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}