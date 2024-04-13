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
    string s; cin >> s;

    v<int> odd, even;
    for (char& c : s) {
        int x = c - '0';
        x & 1 ? odd.push_back(x) : even.push_back(x);
    }
    int n = odd.size(), m = even.size();

    int i = 0, j = 0;
    while (i < n and j < m)
        if (odd[i] < even[j])
            cout << odd[i++];
        else
            cout << even[j++];
    
    while (i < n)
        cout << odd[i++];
    while (j < m)
        cout << even[j++];
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}