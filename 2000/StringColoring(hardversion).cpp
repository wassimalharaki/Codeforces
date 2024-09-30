#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

const int N = 26;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    v<int> ans(n);
    array<int, N> curr; curr.fill(0);
    for (int i = 0; i < n; i++) {
        curr[s[i] - 'a'] = 1;
        for (int j = s[i] - 'a' + 1; j < N; j++)
            curr[s[i] - 'a'] = max(curr[s[i] - 'a'], 1 + curr[j]);
        ans[i] = curr[s[i] - 'a'];
    }
    cout << *max_element(ans.begin(), ans.end()) << nl;
    for (int& x : ans)
        cout << x << " ";
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}