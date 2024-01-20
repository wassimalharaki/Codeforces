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

unordered_set<int> ok;

void solve() {
    int n; cin >> n;
    if (ok.count(n)) {
        cout << "YES" nl;
        return;
    }

    int lo = 1e5, hi = 1e9;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int val = 1 + mid + mid * mid;

        if (val == n) {
            cout << "YES" nl;
            return;
        }
        else if (val > n)
            hi = mid - 1;
        else 
            lo = mid + 1;
    }
    cout << "NO" nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int k = 2; k < 1e6; k++) {
        int sum = 1 + k + k * k;
        int curr = k * k;
        for (int x = 3; 1; x++) {
            ok.insert(sum);
            int a = INF / curr;
            if (a < k) break;
            curr *= k;
            if (curr >= 1e18) break;
            sum += curr;
            if (sum >= 1e18) break;
        }
    }

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}