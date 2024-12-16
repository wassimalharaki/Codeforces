#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

string right_shift(string& s, int k) {
    string t(s.size(), '0');
    for (int i = 0; i + k < s.size(); i++)
        t[i + k] = s[i];
    return t;
}

string left_shift(string& s, int k) {
    string t(s.size(), '0');
    for (int i = 0; i + k < s.size(); i++)
        t[i] = s[i + k];
    return t;
}

string get_xor(string& s, string t) {
    string res(s.size(), '0');
    for (int i = 0; i < s.size(); i++)
        res[i] = char('0' + ((s[i] - '0')^(t[i] - '0')));
    return res;
}

void solve() {
    int n; cin >> n;
    string s, t; cin >> s >> t;

    int s_ones = count(s.begin(), s.end(), '1');
    int t_ones = count(t.begin(), t.end(), '1');
    if (s_ones == 0 and t_ones == 0) {
        cout << 0 << nl;
        return;
    }
    if (s_ones == n and t_ones == n) {
        cout << 0 << nl;
        return;
    }
    if (s_ones and t_ones == 0) {
        cout << -1 << nl;
        return;
    }
    if (t_ones and s_ones == 0) {
        cout << -1 << nl;
        return;
    }
    
    int s_lmost_one = s.find_first_of('1');
    int s_rmost_one = s.find_last_of('1');
    int t_lmost_one = t.find_first_of('1');
    int t_rmost_one = t.find_last_of('1');

    v<int> ops;
    if (s_lmost_one >= t_lmost_one) {
        if (s_lmost_one - t_lmost_one) {
            ops.push_back(s_lmost_one - t_lmost_one);
            s = get_xor(s, left_shift(s, s_lmost_one - t_lmost_one));
        }
        s_lmost_one = s.find_first_of('1');
        for (int i = s_lmost_one + 1; i < n; i++)
            if (s[i] != t[i]) {
                ops.push_back(s_lmost_one - i);
                s = get_xor(s, right_shift(s, i - s_lmost_one));
            }
    }
    else if (s_rmost_one <= t_rmost_one) {
        if (t_rmost_one - s_rmost_one) {
            ops.push_back(s_rmost_one - t_rmost_one);
            s = get_xor(s, right_shift(s, t_rmost_one - s_rmost_one));
        }
        s_rmost_one = s.find_last_of('1');
        for (int i = s_rmost_one - 1; i >= 0; i--)
            if (s[i] != t[i]) {
                ops.push_back(s_rmost_one - i);
                s = get_xor(s, left_shift(s, s_rmost_one - i));
            }
    }
    else {
        s_lmost_one = s.find_first_of('1');
        for (int i = s_lmost_one + 1; i < n; i++)
            if (s[i] != t[i]) {
                ops.push_back(s_lmost_one - i);
                s = get_xor(s, right_shift(s, i - s_lmost_one));
            }
        s_rmost_one = s.find_last_of('1');
        for (int i = s_rmost_one - 1; i >= 0; i--)
            if (s[i] != t[i]) {
                ops.push_back(s_rmost_one - i);
                s = get_xor(s, left_shift(s, s_rmost_one - i));
            }
    }

    cout << ops.size() << nl;
    for (int& x : ops)
        cout << x << " ";
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}