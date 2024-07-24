#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    v<int> a(n);
    for (int i = 0; i < n; i++)
        a[i] = (s[i] == 'A' ? 1 : 0);
    
    v<int> rm(n), sz(n);
    array<int, 2> curr_rm{-1, -1};
    int curr = 0, prev = 2, ans = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] == prev) curr++;
        else curr = 1;
        prev = a[i];
        sz[i] = curr;

        rm[i] = curr_rm[a[i]];
        curr_rm[a[i]] = i;

        {
            int j = rm[i];
            if (j == -1) continue;
            int m = sz[j];
            int k = j - m;
            ans += m;
            if (k == -1) continue;
            ans += k + (curr_rm[!a[i]] > k);
        }
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}