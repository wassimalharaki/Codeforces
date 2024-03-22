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
    string t; cin >> t;

    string s;
    bool ok = 0;
    for (int i = 0; i < n; i++)
        if (ok)
            s.push_back(t[i]);
        else if (t[i] != '0')
            ok = 1, s.push_back(t[i]);
    n = s.size();

    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += s[i] - '0';

    v<int> ans;
    int rem = 0;
    for (int i = 0; i < n; i++) {
        ans.push_back(sum - rem);
        rem += s[n - i - 1] - '0';
    }
    
    int carry = 0;
    for (int i = 0; i < ans.size(); i++) {
        ans[i] += carry;
        carry = ans[i] / 10, ans[i] %= 10;
    }
    if (carry) ans.push_back(carry);
    reverse(all(ans));
    
    for (int& a : ans) cout << a;
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}