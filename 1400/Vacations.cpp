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
    int n; cin >> n;

    int prev = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (a == 0 or ((a == 1 or a == 2) and a == prev))
            ans++, prev = 0;
        else if (a == 3) {
            if (prev == 1)
                prev = 2;
            else if (prev == 2)
                prev = 1;
            else
                prev = a;
        }
        else
            prev = a;
    }
    cout << ans;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}