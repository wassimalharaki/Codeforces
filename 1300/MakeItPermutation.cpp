#include <bits/stdc++.h>

using namespace std;

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

void solve() {
    int n, c, d; cin >> n >> c >> d;

    vi nums(n);
    set<int> set;
    for (int& a : nums) {
        cin >> a;
        set.insert(a);
    }

    int ans = (nums.size() - set.size()) * c;
    if (*set.begin() != 1)
        set.insert(1), ans += d;
    
    nums.clear();
    for (int i : set) nums.pb(i);

    int curr = 0;
    n = nums.size();
    for (int i = nums.size() - 1; i > 0; i--) {
        if (nums[i] - nums[i - 1] == 1) continue;
        int op1 = d * (nums[i] - nums[i - 1] - 1) + curr;
        int op2 = c * (n - i);
        if (op1 > op2) {
            ans += op2 - curr;
            n -= (n - i);
            curr = 0;
        }
        else {
            ans += op1 - curr;
            curr = op1;
        }
    }
    cout << ans << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}