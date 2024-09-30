#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

struct Point {
    int x = -1, y = -1;
    Point(int x, int y) {
        this -> x = x;
        this -> y = y;
    }
    Point() {
        x = -1, y = -1;
    }
};

int dist(Point& p1, Point& p2) {
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

void solve() {
    int n; cin >> n;

    map<int, pair<Point, Point>> layers{
        {0, {Point(0, 0), Point(0, 0)}}
    };
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        int l = max(x, y);
        layers[l];
        Point& left = layers[l].first;
        Point& right = layers[l].second;
        if (left.y < y) {
            left.y = y;
            left.x = x;
        }
        else if (left.x > x) {
            left.x = x;
        }

        if (right.x < x) {
            right.x = x;
            right.y = y;
        }
        else if (right.y > y) {
            right.y = y;
        }
    }

    map<int, int> layer_calc;
    for (auto& [layer, pts] : layers) {
        auto& [left, right] = pts;
        layer_calc[layer] = dist(left, right);
    }

    auto get = [&]() -> int {
        v<array<int, 3>> dp{{0, 0, 0}};
        for (auto& [layer, pts] : layers) {
            auto& [left, right] = pts;

            int a = layer_calc[layer];

            Point& prev_left = layers[dp.back()[0]].first;
            Point& prev_right = layers[dp.back()[0]].second;
            int ans1, ans2;
            {
                int n = dp.back()[1] + dist(left, prev_left);
                int m = dp.back()[2] + dist(left, prev_right);
                ans1 = min(n, m);
            }

            {
                int n = dp.back()[1] + dist(right, prev_left);
                int m = dp.back()[2] + dist(right, prev_right);
                ans2 = min(n, m);
            }
            dp.push_back({layer, ans2 + a, ans1 + a});
        }
        return min(dp.back()[1], dp.back()[2]);
    };
    cout << get();
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}