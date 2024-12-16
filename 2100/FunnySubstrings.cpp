#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

struct node {
    int cnt = 0;
    string beg, end;
};

string haha = "haha";
const int N = 8;

node to_node(string& s) {
    int n = s.size();

    node x;
    for (int i = 0; i < n - 3; i++)
        if (s.substr(i, 4) == haha)
            x.cnt++;
    x.beg = s.substr(0, min(3ll, n));
    x.end = s.substr(max(0ll, n - 3), min(3ll, n));
    return x;
}

node merge(node& x, node& y) {
    string t = x.end + y.beg;
    int n = t.size();

    node res;
    res.cnt = x.cnt + y.cnt;
    for (int i = 0; i < n - 3; i++)
        if (t.substr(i, 4) == haha)
            res.cnt++;
    
    res.beg = x.beg;
    for (int i = 0; i < (int) y.beg.size() and res.beg.size() < 3; i++)
        res.beg.push_back(y.beg[i]);
    res.end = y.end;
    for (int i = x.end.size() - 1; i >= 0 and res.end.size() < 3; i--)
        res.end.insert(res.end.begin(), x.end[i]);
    return res;
}

void solve() {
    int n; cin >> n;

    int ans = 0;
    map<string, node> a;
    for (int i = 0; i < n; i++) {
        string l; cin >> l;
        string op; cin >> op;

        if (op == ":=") {
            string r; cin >> r;
            a[l] = to_node(r);
            ans = a[l].cnt;
        }
        else {
            string x, y; cin >> x >> y >> y;
            a[l] = merge(a[x], a[y]);
            ans = a[l].cnt;
        }
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}