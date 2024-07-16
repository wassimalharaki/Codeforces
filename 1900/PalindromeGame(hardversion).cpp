#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    int x = 0;
    for (int i = 0; i < n / 2; i++)
        x += s[i] != s[n - i - 1];

    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (s[i] == '0' and s[i] == s[n - i - 1])
            cnt++;
    
    int y = 0;
    if (cnt == 1)
        y++;
    else if (cnt & 1)
        y++, x += 2;
    else if (cnt != 0) {
        if (x == 0)
            y = 2;
        else
            y++, x++;
    }
    
    if (x == y)
        cout << "DRAW" << nl;
    else if (x < y)
        cout << "BOB" << nl;
    else
        cout << "ALICE" << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}