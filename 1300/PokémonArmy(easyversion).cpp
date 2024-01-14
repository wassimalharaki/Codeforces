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
    int n, q; cin >> n >> q;

    vi nums(n);
    for (int& a : nums) cin >> a;

    vi answ{nums[0]};
    for (int i = 0; i < n; i++) {
        int m = answ.size();
        if (m & 1) {
            if (nums[i] > answ[m - 1])
                answ[m - 1] = nums[i];
            else
                answ.pb(nums[i]);
        }
        else {
            if (nums[i] > answ[m - 1])
                answ.pb(nums[i]);
            else
                answ[m - 1] = nums[i];
        }
    }

    if (!(answ.size() & 1)) answ.pop_back();

    int sum = 0, curr = 0, alt = 1;
    for (int i = 0; i < answ.size(); i++)
        sum += answ[i] * alt, alt *= -1;
    cout << sum nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}