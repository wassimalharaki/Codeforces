#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

// O(n)
vector<int> z_function(const string& s) {
    int n = s.size();
    vector<int> z(n);

    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i < r)
            z[i] = min(r - i, z[i - l]);

        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
            
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

void solve() {
    string s; cin >> s;
    int n = s.size();
    auto z = z_function(s);

    v<int> diff(n + 2);
    for (int i = 1; i <= n; i++)
        diff[0]++, diff[z[i - 1] + 1]--;
    
    v<int> cnt(n + 1); int curr = 0;
    for (int i = 0; i <= n; i++)
        cnt[i] = 1 + (curr += diff[i]);

    v<int> ans{n};
    for (int i = 0; i < n; i++)
        if (i + z[i] == n)
            ans.push_back(z[i]);
    sort(ans.begin(), ans.end());

    cout << ans.size() << nl;
    for (int& x : ans)
        cout << x << " " << cnt[x] << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}