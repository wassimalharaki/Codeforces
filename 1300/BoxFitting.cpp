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
    int n, w; cin >> n >> w;

    vi nums(21);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        nums[__builtin_ctzll(a)]++;
    }

    int lo = 1, hi = n, answ;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        auto check = [=]() -> bool {
            vi a(nums);
            for (int i = 0; i < mid; i++) {
                int width = w;
                for (int j = 20; j >= 0; j--) {
                    int per = width / (1ll << j);
                    int sub = min(per, a[j]);
                    a[j] -= sub, width -= sub * (1ll << j);
                }
            }
            for (int i = 0; i < 21; i++)
                if (a[i]) return 0;
            return 1;
        };

        if (check())
            hi = mid - 1, answ = mid;
        else
            lo = mid + 1;
    }
    cout << answ nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}