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
    int n, r; cin >> n >> r;

    set<int> nums;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        nums.insert(a);
    }

    int offset = 0, ans = 0;
    for (auto it = nums.rbegin(); it != nums.rend(); it++) {
        int a = *it;
        if (a - offset <= 0) break;
        ans++; offset += r;
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