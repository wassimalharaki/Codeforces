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
    int n, b, h; cin >> n >> b >> h;

    vi nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    
    long double area = b * h / 2.0, answ = area;
    for (int i = 0; i < n - 1; i++) {
        answ += area;
        if (nums[i + 1] - nums[i] >= h)
            continue;
        int d = nums[i + 1] - nums[i];
        answ -= b * (h - d) * (h - d) / (2.0 * h);
    }
    cout << fixed << setprecision(10) << answ nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}