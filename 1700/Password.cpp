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
    string s; cin >> s;
    int n = s.size();

    v<int> pi = kmp(s);
    int m = 0;
    for (int i = 0; i < n - 1; i++)
        m = max(m, pi[i]);
    
    int j = n - 1;
    while (pi[j] > m)
        j = pi[j] - 1;
    cout << (pi[j] ? s.substr(0, pi[j]) : "Just a legend");
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}