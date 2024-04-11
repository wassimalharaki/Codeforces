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
    int n, x; cin >> n >> x;

    v<int> nums(n);
    for (int& a : nums) cin >> a;

    v<int> possib(nums);
    possib.push_back(x);
    sort(all(possib));
    int ans = INT_MAX;
    for (int k = 0; k <= n; k++) {
        v<int> target;
        for (int i = 0; i <= n; i++)
            if (i != k)
                target.push_back(possib[i]);
        v<int> me(nums);

        bool ok = 1;
        int curr = x, need = 0;
        for (int i = 0; i < n; i++) {
            if (me[i] == target[i])
                continue;
            if (me[i] < target[i] or curr > target[i]) {
                ok = 0;
                break;
            }

            for (int j = i + 1; j < n and curr != target[i]; j++) {
                if (me[j] == target[i]) {
                    swap(me[j], curr);
                    need++;
                }
            }

            if (curr == target[i]) {
                swap(curr, me[i]);
                need++;
            }
            else {
                ok = 0;
                break;
            }
        }
        if (ok) ans = min(ans, need);
    }
    cout << (ans == INT_MAX ? -1 : ans) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}