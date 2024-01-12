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
    int pos = 0, neg = 0, z = 0;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        nums[i] > 0 ? pos++ : nums[i] < 0 ? neg++ : z++;
    }
    sort(all(nums));

    if (pos > 2 or neg > 2)
        cout << "NO" nl;
    else if (z > 0 and (pos > 1 or neg > 1))
        cout << "NO" nl;
    else if (pos == 0 and neg == 0)
        cout << "YES" nl;
    else if (z > 0) {
        if (!neg or !pos)
            cout << "YES" nl;
        else if (nums[0] == - nums[n - 1])
            cout << "YES" nl;
        else
            cout << "NO" nl;
    }
    else if (n == 3)
        cout << (count(all(nums), accumulate(all(nums), 0ll)) ? "YES" : "NO") nl;
    else {
        int a = nums[0] + nums[1] + nums[2];
        int b = nums[0] + nums[1] + nums[3];
        int c = nums[0] + nums[2] + nums[3];
        int d = nums[1] + nums[2] + nums[3];
        if (count(all(nums), a)
                and count(all(nums), b)
                and count(all(nums), c)
                and count(all(nums), d))
            cout << "YES" nl;
        else
            cout << "NO" nl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}