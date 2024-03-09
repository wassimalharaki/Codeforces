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
    string s; cin >> s;

    set<char> dist;
    for (char& c : s)
        dist.insert(c);
    int max = dist.size();

    map<char, int> have;
    int l = 0, r = -1, ans = n;
    while (1) {
        if (have.size() < max) {
            if (++r >= n) break;
            have[s[r]]++;
        }
        else {
            ans = min(ans, r - l + 1);
            have[s[l]]--;
            if (have[s[l]] == 0)
                have.erase(s[l]);
            l++;
        }
    }
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}