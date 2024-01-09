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

bool perm(vi& nums) {
    sort(all(nums));
    for (int i = 0; i < nums.size(); i++)
        if (nums[i] != i + 1)
            return 0;
    return 1;
}

void solve() {
    int n; cin >> n;

    if (n == 1) {
        cout << 1 nl;
        return;
    }
    if (n & 1) {
        cout << -1 nl;
        return;
    }

    int a = n, add = n - 1;
    int alt = -1;
    int der = -1;
    cout << a << " ";
    for (int i = 0; i < n - 1; i++) {
        a += add * alt;
        cout << a << " ";
        if (add == 1 and der == -1) {
            der = 1;
            continue;
        }
        add += der * 2;
        alt *= -1;
    }
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