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

    set<int> nums;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        nums.insert(a);
    }

    if (nums.size() > 3) {
        cout << -1;
        return;
    }

    if (nums.size() == 1) {
        cout << 0;
        return;
    }

    int a = *(++nums.begin()) - *nums.begin();
    if (nums.size() == 2) {
        cout << (a & 1 ? a : a / 2);
        return;
    }

    int b = *(++(++nums.begin())) - *(++nums.begin());
    cout << (a == b ? a : -1);
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}