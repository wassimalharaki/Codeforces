#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector
#define all(v) v.begin(), v.end()

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

const int mod = 1e9 + 7;
const int N = 2e5 + 10;
int precomp[10][N];

void solve() {
    int n, m; cin >> n >> m;

    int ans = 0;
    while (n) {
        ans = (ans + precomp[n % 10][m]) % mod;
        n /= 10;
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    memset(precomp, 0, sizeof(precomp));
    v<int> nums(10);
    nums[0] = 1;
    for (int j = 1; j < N; j++) {
        int x = nums[9]; nums[9] = 0;
        for (int k = 8; k >= 0; k--) {
            nums[k + 1] = nums[k];
            nums[k] = 0;
        }
        nums[0] = x;
        nums[1] = (nums[1] + x) % mod;
        for (int i = 0; i < 10; i++)
            if (j - i >= 0)
                precomp[i][j - i] = accumulate(all(nums), 0ll) % mod;
    }

    int T = 1;
    cin >> T;
    while (T--) solve();
}