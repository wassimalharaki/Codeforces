#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

// O(n)
vector<int> kmp(const string& s) {
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
    int n; cin >> n;
    string s; cin >> s;
    for (int i = 0; i < n - 1; i++) {
        string t; cin >> t;
        int l = max(0, (int) s.size() - (int) t.size());
        int sz = (int) s.size() - l;
        string u = s.substr(l, sz);
        int x = kmp(t + "$" + u).back();
        s += t.substr(x, (int) t.size() - x);
    }
    cout << s << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}