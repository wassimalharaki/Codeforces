#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;

    v<string> a(3);
    v<int> o;
    for (string& s : a) {
        cin >> s;
        o.push_back(count(s.begin(), s.end(), '1'));
    }

    string s, t;
    for (int i = 0; i < 3; i++)
        for (int j = i + 1; j < 3; j++) {
            if (o[i] >= n and o[j] >= n)
                s = a[i], t = a[j];
            if (o[i] < n and o[j] < n)
                s = a[i], t = a[j];
        }
    
    int os = count(s.begin(), s.end(), '1');
    int ot = count(t.begin(), t.end(), '1');

    char tgt, add;
    int m;
    if (os >= n and ot >= n) {
        tgt = '1';
        add = '0';
        m = max(os, ot);
    }
    else {
        tgt = '0';
        add = '1';
        m = max(2 * n - os, 2 * n - ot);
    }

    queue<int> qs, qt;
    int cnt = 0;
    for (char& c : s)
        if (c == tgt)
            cnt++;
        else
            qs.push(cnt);
    cnt = 0;
    for (char& c : t)
        if (c == tgt)
            cnt++;
        else
            qt.push(cnt);
    
    string ans;
    for (int i = 0; i < m; i++) {
        while (qs.size() and qs.front() == i) {
            ans.push_back(add);
            qs.pop();
        }
        while (qt.size() and qt.front() == i) {
            ans.push_back(add);
            qt.pop();
        }
        ans.push_back(tgt);
    }
    ans += string(qs.size() + qt.size(), add);
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}