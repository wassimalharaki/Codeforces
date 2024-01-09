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

struct Rectangle {
    int l, r, u, d;
    Rectangle(int l, int r, int u, int d) {
        this -> l = l;
        this -> r = r;
        this -> u = u;
        this -> d = d;
    }

    void remax(int i, int j) {
        l = min(j, l);
        r = max(r, j);
        u = max(i , u);
        d = min(d, i);
    }
};

void solve() {
    int n, m; cin >> n >> m;

    vvi nums(n, vi(m));
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++)
            nums[i][j] = (s[j] == '1');
    }
    vvi table(nums);

    v<Rectangle> rects;

    vi dx{1, 0, -1, 0};
    vi dy{0, 1, 0, -1};

    auto is_valid = [&](int i, int j) {
        return i >= 0 and j >= 0 and i < n and j < m;
    };

    function<void(int i, int j)> dfs = [&](int i, int j) {
        rects[rects.size() - 1].remax(i, j);

        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if (not is_valid(ni, nj) or not nums[ni][nj])
                continue;

            nums[ni][nj] = 0;
            dfs(ni, nj);
        }
    };

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (nums[i][j]) {
                rects.pb(Rectangle(j, j, i, i));
                nums[i][j] = 0;
                dfs(i, j);
            }
    
    for (int k = 0; k < rects.size(); k++) {
        Rectangle& r = rects[k];
        for (int i = r.d; i <= r.u; i++)
            for (int j = r.l; j <= r.r; j++)
                if (table[i][j] == 0) {
                    cout << "NO" nl;
                    return;
                }
    }
    cout << "YES" nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}