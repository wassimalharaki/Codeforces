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
    Point(int x, int y) {
        this -> x = x;
        this -> y = y;
    }
};

int dist(Point& a, Point& b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

void solve() {
    int n, m; cin >> n >> m;

    v<Point> corners{
        Point(0, 0),
        Point(0, n - 1),
        Point(m - 1, 0),
        Point(m - 1, n - 1)
    };

    vi distances;
    for (int y = 0; y < n; y++)
        for (int x = 0; x < m; x++) {
            Point p(x, y);
            int max = -INF;
            for (int i = 0; i < 4; i++)
                max = std::max(max, dist(p, corners[i]));
            distances.pb(max);
        }
    sort(all(distances));

    for (int i = 0; i < n * m; i++)
        cout << distances[i] << " ";
    cout nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}