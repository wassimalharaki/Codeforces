#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n; cin >> n;
 
    map<int, vector<int>> nums;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        nums[a].push_back(i + 1);
    }
 
    int a = -1, l = -1, r = -1, max = -1;
    for (auto& [key, ind] : nums) {
        int curr = 1, x = ind[0], y = ind[0];
        for (int i = 1; i < ind.size(); i++) {
            int diff = ind[i] - ind[i - 1] - 1;
            if (curr + 1 - diff <= 0) {
                curr = 1;
                x = ind[i], y = ind[i];
            }
            else {
                curr += 1 - diff;
                y = ind[i];
            }
            if (curr > max) {
                a = key;
                l = x; r = y;
                max = curr;
            }
        }
        if (curr > max) {
            a = key;
            l = x; r = y;
            max = curr;
        }
    }
    cout << a << " " << l << " " << r << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}