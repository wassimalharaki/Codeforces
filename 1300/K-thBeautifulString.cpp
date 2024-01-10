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
    int n, k; cin >> n >> k;

    int lo = 1, hi = 2e5, x;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int val = (mid + 1) * mid / 2;

        if (val >= k)
            x = mid, hi = mid - 1;
        else
            lo = mid + 1;
    }
    string answ(n, 'a');
    answ[n - x - 1] = 'b';
    int diff = (x + 1) * x / 2 - k + 1;
    answ[n - x - 1 + diff] = 'b';
    cout << answ nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}