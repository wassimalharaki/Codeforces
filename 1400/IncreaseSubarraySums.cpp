#include <bits/stdc++.h>

using namespace std;

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

#define int long long
#define INF LONG_LONG_MAX
#define nl '\n'
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

int max(int a, int b) {
    return std::max(a, b);
}

int min(int a, int b) {
    return std::min(a, b);
}

template <class S, S (*op)(S, S)>
struct sparse_table {

    public:

        sparse_table(v<S>& nums) {
            d = v<v<S>>(n + 1, v<S>(nums.size()));
            copy(nums.begin(), nums.end(), d[0].begin());

            for (int i = 1; i <= n; i++)
                for (int j = 0; j + (1 << i) <= nums.size(); j++)
                    d[i][j] = op(d[i - 1][j], d[i - 1][j + (1 << (i - 1))]);
        }

        S prod(int l, int r) {
            int i = 63 - __builtin_clzll(r - l);
            return op(d[i][l], d[i][r - (1 << i)]);
        }

    private:

        const int n = 25;
        v<v<S>> d;
};

void solve() {
    int n, x; cin >> n >> x;

    vi nums(n);
    for (int& a : nums) cin >> a;

    vi prefix(n + 1);
    partial_sum(all(nums), prefix.begin() + 1);
    sparse_table<int, max> max_table(prefix);
    sparse_table<int, min> min_table(prefix);

    int prev = 0;
    for (int k = 0; k <= n; k++) {
        int left, right;
        for (int i = 0; i <= n - k; i++) {
            left = min_table.prod(0, i + 1);
            right = max_table.prod(k + i, n + 1);
            prev = max(prev, right - left + k * x);
        }
        cout << prev << " ";
    }
    cout << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}