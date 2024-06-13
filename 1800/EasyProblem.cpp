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

using ai2 = array<int, 2>;
using ai4 = array<int, 4>;
string s = "hard";

void solve() {
    int n; cin >> n;

    v<ai2> a(n);
    for (auto& x : a) {
        char c; cin >> c;
        x[0] = c;
    }
    for (auto& x : a)
        cin >> x[1];
    
    v<ai2> b;
    ai4 have; have.fill(0);
    for (int i = n - 1; i >= 0; i--) {
        int j = s.find(char(a[i][0]));
        if (j != -1 and (j == 3 or have[j + 1])) {
            have[j] = 1;
            b.push_back(a[i]);
        }
    }
    reverse(b.begin(), b.end());
    a.swap(b);
    n = a.size();

    if (have[0] * have[1] * have[2] * have[3] == 0) {
        cout << 0;
        return;
    }

    b = {a[0]};
    for (int i = 1; i < n; i++)
        if (a[i][0] == b.back()[0])
            b.back()[1] += a[i][1];
        else
            b.push_back(a[i]);
    a.swap(b);
    n = a.size();
    
    ai4 dp; dp.fill(0);
    for (int i = n - 1; i >= 0; i--) {
        int j = s.find(char(a[i][0]));
        if (j == 3)
            dp[j] += a[i][1];
        else
            dp[j] = min(a[i][1] + dp[j], dp[j + 1]);
    }
    cout << *min_element(dp.begin(), dp.end());
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int T = 1;
    // cin >> T;
    while (T--) solve();
}