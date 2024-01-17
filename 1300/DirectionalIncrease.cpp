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

    vi nums(n), curr(n);
    int a = -1;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        if (nums[i]) a = i;
    }

    if (a == -1) {
        cout << "Yes" nl;
        return;
    }

    if (nums[a] > 0) {
        cout << "No" nl;
        return;
    }

    if (nums[0] <= 0) {
        cout << "No" nl;
        return;
    }

    for (int i = 0; i < a; i++)
        curr[i]++;
    curr[a] = nums[a];
    curr[a - 1] += abs(nums[a]) - 1;

    for (int i = a - 1; i > 0; i--)
        if (nums[i] > curr[i]) {
            cout << "No" nl;
            return;
        }
        else if (curr[i] - nums[i] > 0) {
            int diff = curr[i] - nums[i];
            curr[i] = nums[i];
            curr[i - 1] += diff - 1;
        }
    cout << (curr[0] == nums[0] ? "Yes" : "No") nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}