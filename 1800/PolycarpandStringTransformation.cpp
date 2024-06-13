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

const int N = 26;

bool valid(string s, v<char>& a, string& t) {
    string curr;
    for (int i = 0; i < a.size(); i++) {
        curr += s;
        string u;
        for (char& c : s)
            if (c != a[i])
                u.push_back(c);
        s.swap(u);
    }
    return curr == t;
}

void solve() {
    string t; cin >> t;
    int n = t.size();

    v<char> a;
    array<int, N> dead, cnt;
    cnt.fill(0); dead.fill(0);
    for (int i = n - 1; i >= 0; i--) {
        cnt[t[i] - 'a']++;
        if (not dead[t[i] - 'a'])
            dead[t[i] - 'a'] = 1, a.push_back(t[i]);
    }
    reverse(a.begin(), a.end());

    array<int, N> x, y;
    x.fill(0), y.fill(0);
    for (int i = 0; i < N; i++)
        if (dead[i]) {
            x[i] = find(a.begin(), a.end(), char('a' + i))
                    - a.begin() + 1;
            if (cnt[i] % x[i]) {
                cout << -1 << nl;
                return;
            }
            y[i] = cnt[i] / x[i];
        }

    string s;
    for (int i = 0; i < n and *max_element(y.begin(), y.end()); i++)
        y[t[i] - 'a']--, s.push_back(t[i]);
    
    if (not valid(s, a, t))
        cout << -1 << nl;
    else {
        cout << s << " ";
        for (char& c : a)
            cout << c;
        cout << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}