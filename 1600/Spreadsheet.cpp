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

    v<string> split{string{s[0]}};
    for (int i = 1; i < n; i++) {
        char& c = s[i];
        string& t = split.back();
        if (isalpha(c)) {
            if (isalpha(t.back()))
                t.push_back(c);
            else
                split.push_back(string{c});
        }
        else {
            if (isdigit(t.back()))
                t.push_back(c);
            else
                split.push_back(string{c});
        }
    }

    if (split.size() == 2) {
        int x = 0;
        for (char& c : split[0])
            x = x * 26 + (c - 'A' + 1);
        cout << "R" << split[1] << "C" << x << nl;
    }
    else {
        int x = stoll(split[3]);
        string t;
        while (x) {
            if (x % 26 == 0)
                t.push_back('Z'), x -= 26;
            else
                t.push_back(char(x % 26 + 'A' - 1));
            x /= 26;
        }
        reverse(all(t));
        cout << t << split[1] << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}