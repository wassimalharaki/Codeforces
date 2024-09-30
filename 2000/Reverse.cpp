#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

const int N = 63;

string get(int x) {
    string s;
    for (int i = 0; i < N and x; i++) {
        s += char('0' + (int) (((1ll << i) & x) > 0));
        x -= (1ll << i) & x;
    }
    reverse(s.begin(), s.end());
    return s;
}

int cto(string s) {
    int n = s.size(), ans = 0;
    for (int i = n - 1; i >= 0; i--)
        if (s[i] == '1')
            ans++;
        else break;
    return ans;
}

int clo(string s) {
    int n = s.size(), ans = 0;
    for (int i = 0; i < n; i++)
        if (s[i] == '1')
            ans++;
        else break;
    return ans;
}

bool try_this(string s, string t) {
    while (cto(s) < cto(t))
        s += "1";
    while (clo(s) < clo(t))
        s = "1" + s;
    
    if (s == t) return 1;
    reverse(s.begin(), s.end());
    return s == t;
}

bool check(string s, string t) {
    if (try_this(s, t)) return 1;
    reverse(s.begin(), s.end());
    return try_this(s, t);
}

void solve() {
    int x, y; cin >> x >> y;
    string s = get(x), t = get(y);

    if (s == t) {
        cout << "YES" << nl;
        return;
    }

    while (s.back() == '0')
        s.pop_back();
    bool ans = check(s, t);

    s = get(x);
    if (s.back() == '0') {
        s += "1";
        ans |= check(s, t);
    }
    cout << (ans ? "YES" : "NO") << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}