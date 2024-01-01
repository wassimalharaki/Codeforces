#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define nl << '\n'
#define pii pair<int, int>
#define v vector
#define vi v<int>
#define vvi v<vi>
#define vpii v<pii>
#define mp make_pair
#define pb push_back
#define INF LONG_LONG_MAX
#define F first
#define S second

struct Point {
    int x, y;
    bool operator<(const Point& p) const {
        if (x == p.x)
            return y < p.y;
        return x < p.x;
    }
};

void solve() {
    int n; cin >> n;

    v<Point> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i].x >> nums[i].y;
    sort(all(nums));

    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        int dx = nums[i].x - x;
        int dy = nums[i].y - y;

        if (dx < 0 or dy < 0) {
            cout << "NO" nl;
            return;
        }

        x = nums[i].x;
        y = nums[i].y;
    }

    cout << "YES" nl;
    x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        int dx = nums[i].x - x;
        int dy = nums[i].y - y;

        for (int j = 0; j < dx; j++)
            cout << 'R';
        for (int j = 0; j < dy; j++)
            cout << 'U';
        
        x = nums[i].x;
        y = nums[i].y;
    }
    cout nl;
}

int32_t main() {
    fast;

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}