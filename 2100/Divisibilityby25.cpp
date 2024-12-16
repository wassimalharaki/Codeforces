#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    string s; cin >> s;
    reverse(s.begin(), s.end());
    int n = s.size();

    if (n == 1)
        return void(cout << -1 << nl);

    int ans = LLONG_MAX;
    for (string t : {"00", "52", "05", "57"}) {
        if (s == t)
            return void(cout << 0 << nl);
        string u = s;
        int x = 0;

        int i = u.find(t[0]);
        int j = u.find(t[1]);
        if (i == j) j = u.find(t[1], i + 1);
        if (i == -1 or j == -1) continue;

        if (i == n - 1 and u[i - 1] == '0')
            for (int k = n - 2; k >= 0; k--) {
                if (j == k) continue;
                if (u[k] == '0') continue;
                for (; k < n - 2; k++, x++)
                    swap(u[k], u[k + 1]);
                break;
            }
        
        if (i == n - 1 and u[i - 1] == '0')
            continue;
        for (; i; i--, x++)
            swap(u[i - 1], u[i]);
        
        j = u.find(t[1], 1);
        if (j == n - 1 and u[j - 1] == '0')
            for (int k = n - 2; k >= 0; k--) {
                if (i == k) continue;
                if (u[k] == '0') continue;
                for (; k < n - 2; k++, x++)
                    swap(u[k], u[k + 1]);
                break;
            }

        if (j == n - 1 and u[j - 1] == '0')
            continue;
        for (; j > 1; j--, x++)
            swap(u[j - 1], u[j]);

        ans = min(ans, x);
    }
    cout << (ans == LLONG_MAX ? -1 : ans) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}