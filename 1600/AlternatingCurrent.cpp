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
    int n = s.size();

    stack<char> st;
    for (int i = 0; i < n; i++)
        if (st.size() and st.top() == s[i])
            st.pop();
        else
            st.push(s[i]);
    cout << (st.empty() ? "Yes" : "No");
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}