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

void solve() {
    int n, m, h; cin >> n >> m >> h;

    vvi nums(n, vi(m));
    vpii scores(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> nums[i][j];
        sort(all(nums[i]));
        int penalty = 0, time = 0, points = 0, j = 0;
        while (j < m) {
            if (time + nums[i][j] > h)
                break;
            time += nums[i][j];
            penalty += time;
            points++;
            j++;
        }
        scores[i].F = points, scores[i].S = penalty;
    }

    int count = 0;
    for (int i = 1; i < n; i++)
        if (scores[i].F > scores[0].F)
            count++;
        else if (scores[i].F == scores[0].F)
            if (scores[i].S < scores[0].S)
                count++;
    cout << count + 1 nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}