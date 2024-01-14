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

    vi nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    
    int c = max_element(all(nums)) - nums.begin();
    v<bool> flag(n); flag[c] = 1;
    vi answ{nums[c]};
    c = nums[c];
    for (int i = 1; i < n; i++) {
        int max = -INF, imax;
        for (int j = 0; j < n; j++) {
            if (flag[j]) continue;
            int g = gcd(c, nums[j]);
            if (g > max)
                max = g, imax = j;
            else if (g == max and nums[j] < nums[imax])
                imax = j;
        }
        answ.pb(nums[imax]);
        c = gcd(c, nums[imax]);
        flag[imax] = 1;
    }
    for (int i = 0; i < n; i++)
        cout << answ[i] << " ";
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