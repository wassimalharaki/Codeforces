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

void solve() {
    int n, k; cin >> n >> k;

    if (k > (n - 2) * n / 4) {
        cout << -1 << nl;
        return;
    }

    v<array<int, 2>> nums(n / 2);
    int l = 0, r = n - 1;
    for (int i = 0; i < n / 2; i++)
        nums[i] = {r--, l++};

    if (k != n - 1) {
        for (int i = 0; i < n / 2; i++) {
            if (nums[i][0] == k) {
                swap(nums[i][0], nums[0][1]);
                break;
            }
            if (nums[i][1] == k) {
                swap(nums[i][1], nums[0][1]);
                break;
            }
        }
    }
    else {
        swap(nums[1][0], nums[0][1]);
        swap(nums[1][0], nums[2][0]);
    }
    for (int i = 0; i < n / 2; i++)
        cout << nums[i][0] << " " << nums[i][1] << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}