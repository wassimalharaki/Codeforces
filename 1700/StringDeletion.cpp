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
    string s; cin >> s;

    v<int> blocks{1}, block_id(n);
    for (int i = 1; i < n; i++)
        if (s[i] == s[i - 1]) {
            block_id[i] = block_id[i - 1];
            blocks.back()++;
        }
        else {
            block_id[i] = 1 + block_id[i - 1];
            blocks.push_back(1);
        }
    
    int l = 0, r = n - 1, i = 0, ans = 0;
    while (l <= r) {
        i = max(i, block_id[l]);
        while (i < blocks.size() and blocks[i] == 1)
            i++;

        if (i >= blocks.size()) {
            char prev = s[r--];
            while (r >= 0 and s[r] != prev) r--;
            r++;
        }
        else if (i == blocks.size() - 1) r--, blocks[i]--;
        else blocks[i]--;

        ans++;
        int j = block_id[l];
        while (l <= r and block_id[l] == j) l++;
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}