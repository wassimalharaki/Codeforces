#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

// O(n)
vector<int> kmp(string& s) {
    int n = s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

void solve() {
    v<string> a(3);
    cin >> a[0] >> a[1] >> a[2];
    sort(a.begin(), a.end());

    int ans = 1e18;
    do {
        string s = a[0];
        for (int i = 1; i < 3; i++) {
            string t = a[i] + "$" + s;
            auto pi = kmp(t);
            if (find(pi.begin(), pi.end(), a[i].size()) != pi.end())
                continue;
            int x = pi.back();
            s += a[i].substr(x, a[i].size() - x);
        }
        ans = min(ans, (int) s.size());
    } while (next_permutation(a.begin(), a.end()));
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}