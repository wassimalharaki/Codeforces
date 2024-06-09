#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

using S = int;

int op(int a, int b) {
    return min(a, b);
}

int e() {
    return 0;
}

// O(nlog(n)), O(1)
// template <class S, S (*op)(S, S), S (*e)()>
struct sparse_table {
    vector<vector<S>> d;

    sparse_table(vector<S>& a) {
        int n = a.size(), k = 64 - __builtin_clzll(n);
        d.resize(k, vector<S>(n));
        copy(a.begin(), a.end(), d[0].begin());

        for (int i = 1; i <= k; i++)
            for (int j = 0; j + (1 << i) <= n; j++)
                d[i][j] = op(d[i - 1][j], d[i - 1][j + (1 << (i - 1))]);
    }

    S prod(int l, int r) {
        if (l == r) return e();
        int i = 63 - __builtin_clzll(r - l);
        return op(d[i][l], d[i][r - (1 << i)]);
    }
};

void solve() {
    string s; cin >> s;
    int n = s.size();

    int o = count(s.begin(), s.end(), '(');
    int c = count(s.begin(), s.end(), ')');
    int q = n - o - c;

    if (o == n / 2 or c == n / 2) {
        cout << "YES" << nl;
        return;
    }

    v<int> o_i;
    for (int i = 0; i < n and o < n / 2; i++)
        if (s[i] == '?')
            o_i.push_back(i), o++;

    int j = 0;
    for (int i = o_i.back() + 1; i < n and !j; i++)
        if (s[i] == '?')
            j = i;
    
    v<int> bal(n);
    bal[0] = 1;
    for (int i = 1; i < n; i++)
        if (s[i] == '(' or (s[i] == '?' and i <= o_i.back()))
            bal[i] = bal[i - 1] + 1;
        else
            bal[i] = bal[i - 1] - 1;
    sparse_table ok(bal);

    for (int& i : o_i)
        if (ok.prod(i, j) >= 2) {
            cout << "NO" << nl;
            return;
        }
    cout << "YES" << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}