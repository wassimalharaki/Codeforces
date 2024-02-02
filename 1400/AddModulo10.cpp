#include <bits/stdc++.h>

using namespace std;

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

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

void op(int& i) { i += i % 10; }

void solve() {
    int n; cin >> n;

    vi nums(n);
    for (int& a : nums) cin >> a;

    bool ok = 0;
    for (int i = 0; i < n; i++)
        if (nums[i] % 10 == 0 or nums[i] % 5 == 0)
            ok = 1;
    
    if (ok) {
        for (int i = 0; i < n; i++) op(nums[i]);

        for (int i = 0; i < n - 1; i++)
            if (nums[i] != nums[i + 1]) {
                cout << "No" << nl;
                return;
            }
        cout << "Yes" << nl;
        return;
    }
    sort(all(nums));

    while (nums.back() % 10 != 2) op(nums.back());
    for (int i = 0; i < n - 1; i++) {
        while (nums[i] % 10 != 2) op(nums[i]);
        if ((nums.back() - nums[i]) % 20) {
            cout << "No" << nl;
            return;
        }
    }
    cout << "Yes" << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}