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

    v<int> cnt(n + 1);
    multiset<int> have;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        have.insert(x);
        cnt[x]++;
    }

    int sum = 0, prev = 0;
    for (int i = 0; i <= n; i++) {
        if (sum < i) prev = -1;
        if (prev == -1) {
            cout << prev << " ";
            continue;
        }
        
        if (i) {
            if (cnt[i - 1] == 0) {
                auto it = have.lower_bound(i);
                --it;
                prev += i - 1 - *it;
                have.erase(it);
            }
            else
                have.erase(have.find(i - 1));
        }

        cout << prev + cnt[i] << " ";
        sum += cnt[i];
    }
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}