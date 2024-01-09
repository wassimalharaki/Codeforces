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

    vi nums(n), odd(n + 1), even(n + 1), prefix(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        odd[i + 1] = odd[i] + (nums[i] & 1);
        even[i + 1] = even[i] + !(nums[i] & 1);
        prefix[i + 1] = prefix[i] + nums[i];
    }

    cout << prefix[1] << " ";
    for (int i = 2; i <= n; i++) {
        int times = odd[i] / 3 + (odd[i] % 3 == 1);
        cout << prefix[i] - times << " ";
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