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
    int n; cin >> n;

    set<int> use;
    v<int> nums(n);
    for (int& a : nums) cin >> a;

    v<bool> dead(n + 1);
    for (int i = 0; i < n; i++)
        dead[nums[i]] = 1;

    for (int i = 1; i <= n; i++)
        if (not dead[i])
            use.insert(i);
    
    set<int> kill;
    for (int i = 0; i < n; i++) {
        if (nums[i]) continue;
        if (not use.count(i + 1)) continue;
        use.erase(i + 1);
        kill.insert(i + 1);
    }

    for (int i = 0; i < n and kill.size(); i++) {
        if (nums[i]) continue;
        int a = *kill.begin(), b = *kill.rbegin();
        if (a != i + 1)
            nums[i] = a, kill.erase(a);
        else if (b != i + 1)
            nums[i] = b, kill.erase(b);
    }

    for (int i = 0; i < n; i++) {
        if (nums[i]) continue;
        int a = *use.begin(), b = *use.rbegin();
        if (a != i + 1)
            nums[i] = a, use.erase(a);
        else
            nums[i] = b, use.erase(b);
    }
    for (int& a : nums) cout << a << " ";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}