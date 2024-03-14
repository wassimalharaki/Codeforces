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

vector<int> kmp(string& s) {
    int n = s.length();
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

string get(string s) {
    string u = s + '!';
    reverse(all(s));
    u += s;
    v<int> pi = kmp(u);
    return u.substr(0, pi.back());
}

void solve() {
    string s; cin >> s;
    int n = s.size();

    if (n == 1) {
        cout << s << nl;
        return;
    }

    int i = 0, j = n - 1;
    while (i <= j)
        if (s[i] != s[j]) break;
        else i++, j--;
    
    if (i > j) {
        cout << s << nl;
        return;
    }
    string left = s.substr(0, i), right = s.substr(j + 1, n - j + 2);

    string t = s.substr(i, j - i + 1);
    string pref_l = get(t);
    reverse(all(t));
    string pref_r = get(t);

    string middle = (pref_l.size() > pref_r.size() ? pref_l : pref_r);
    cout << left + middle + right << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}