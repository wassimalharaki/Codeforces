#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

const long double eps = 1e-9;

bool eq(long double a, long double b) {
    return abs(a - b) <= eps;
}

struct Point {
    long double x, y;
    Point(long double _x, long double _y) {
        x = _x, y = _y;
    }
};

struct Line {
    long double m, b, x;
    bool vert;
    Line(Point& p1, Point& p2) {
        if (eq(p1.x, p2.x)) {
            m = DBL_MAX;
            b = DBL_MAX;
            x = p1.x;
            vert = 1;
        }
        else {
            m = (p2.y - p1.y) / (p2.x - p1.x);
            b = p1.y - m * p1.x;
            vert = 0;
        }
    }
};

Point intersect(Line& l1, Line& l2) {
    if (eq(l1.m, l2.m) or (l1.vert and l2.vert))
        return Point(DBL_MAX, DBL_MAX);

    if (not l1.vert and not l2.vert)
        return Point((l2.b - l1.b) / (l1.m - l2.m), l1.m * (l2.b - l1.b) / (l1.m - l2.m) + l1.b);
    else if (l1.vert)
        return Point(l1.x, l2.m * l1.x + l2.b);
    else
        return Point(l2.x, l1.m * l2.x + l1.b);
}

bool contained(Point& p, long double w, long double h) {
    if (p.x < - w / 2 or p.x > w / 2)
        return 0;
    if (p.y < - h / 2 or p.y > h / 2)
        return 0;
    return 1;
}

const long double PI = numbers::pi_v<long double>;

long double degrees_to_rad(long double a) {
    return a * PI / 180;
}

long double area(const vector<Point>& fig) {
    long double res = 0;
    for (unsigned i = 0; i < fig.size(); i++) {
        Point p = i ? fig[i - 1] : fig.back();
        Point q = fig[i];
        res += (p.x - q.x) * (p.y + q.y);
    }
    return fabs(res) / 2;
}

void solve() {
    long double w, h, a; cin >> w >> h >> a;

    if (eq(a, 0) or eq(a, 180) or (eq(a, 90) and eq(w, h))) {
        cout << w * h << nl;
        return;
    }
    a = degrees_to_rad(a);


    long double half_width = w / 2, half_height = h / 2;
    Point orig_tr(half_width, half_height);
    Point orig_tl(-half_width, half_height);
    Point orig_bl(-half_width, -half_height);
    Point orig_br(half_width, -half_height);

    long double half_diag = sqrt((w * w + h * h) / 4);
    long double b = acos(half_width / half_diag);
    Point new_tr(half_diag * cos(a + b), half_diag * sin(a + b));
    Point new_tl(half_diag * cos(a + PI - b), half_diag * sin(a + PI - b));
    Point new_bl(half_diag * cos(a + b + PI), half_diag * sin(a + b + PI));
    Point new_br(half_diag * cos(a - b), half_diag * sin(a - b));

    v<Line> orig_sqr{
        Line(orig_tl, orig_tr),
        Line(orig_tl, orig_bl),
        Line(orig_bl, orig_br),
        Line(orig_br, orig_tr)
    };

    v<Line> new_sqr{
        Line(new_tl, new_tr),
        Line(new_tl, new_bl),
        Line(new_bl, new_br),
        Line(new_br, new_tr)
    };

    v<Point> inter_points;
    for (int i = 0; i < 4; i++)
        for (int j = i - 2; j <= i; j++) {
            Point p = intersect(orig_sqr[i], new_sqr[(j + 4) % 4]);
            if (contained(p, w, h))
                inter_points.push_back(p);
        }

    cout << area(inter_points) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}