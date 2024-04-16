#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector
#define all(v) v.begin(), v.end()

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

int ask(int x, int y) {
    cout << "? " << x << " " << y << endl;
    int a; cin >> a;
    return a;
}

void solve() {
    int n; cin >> n;

    v<int> nums(n), ans(n + 1), used(n + 1);
    iota(all(nums), 1ll);
    while (nums.size() > 1) {
        int x = nums.back();
        nums.pop_back();
        int y = nums.back();
        nums.pop_back();

        int a = ask(x, y);
        int b = ask(y, x);
        if (a > b) {
            ans[x] = a;
            used[a] = 1;
            nums.push_back(y);
        }
        else {
            ans[y] = b;
            used[b] = 1;
            nums.push_back(x);
        }
    }

    for (int i = 1; i <= n; i++)
        if (not used[i])
            ans[nums[0]] = i;

    cout << "! ";
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;
}

signed main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}