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
    int n; cin >> n;
    n *= 4;

    vi nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    sort(all(nums));

    int area = -1;
    for (int i = 0; i < n / 2; i += 2) {
        vi rect{
            nums[i],
            nums[i + 1],
            nums[n - i - 1],
            nums[n - i - 2]
        };
        int a = accumulate(all(rect), 1ll, multiplies<int>());

        if (rect[0] != rect[1] or rect[2] != rect[3]) {
            cout << "NO" nl;
            return;
        }

        if (area == -1)
            area = a;
        else if (a != area) {
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