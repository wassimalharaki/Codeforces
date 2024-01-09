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

struct Point {
    int x, y;
    Point() {}
    Point(int x, int y) {
        this -> x = x;
        this -> y = y;
    }
};

double dist(Point& p1, Point& p2) {
    int a = p2.y - p1.y, b = p2.x - p1.x;
    return sqrt(a * a + b * b);
}

void solve() {
    Point h, a, b, me(0, 0);
    cin >> h.x >> h.y;
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;

    double a1 = max(dist(a, me), dist(a, h));
    double b1 = max(dist(b, me), dist(b, h));

    double inter = dist(a, b) / 2;
    double ame = dist(a, me), ah = dist(a, h);
    double bme = dist(b, me), bh = dist(b, h);
    cout << fixed << setprecision(10) << min({
        a1,
        b1,
        max(inter, min(max(ame, bh), max(bme, ah)))
    }) nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}