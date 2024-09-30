#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

void add_edges(int x) {
    cout << "+ " << x << endl;
    cin >> x; assert(x != -2);
}

int ask(int i, int j) {
    cout << "? " << i + 1 << " " << j + 1 << endl;
    int x; cin >> x;
    assert(x != -1);
    assert(x != -2);
    return x;
}

void solve() {
    int n; cin >> n;
    add_edges(n);
    add_edges(n + 1);

    int j = -1, best = 0;
    for (int i = 1; i < n; i++) {
        int dist = ask(0, i);
        if (dist > best)
            best = dist, j = i;
    }

    v<int> ans1(n), ans2(n);
    ans1[j] = n, ans2[j] = (n + 1) / 2;
    for (int i = 0; i < n; i++) {
        if (i == j) continue;
        int dist = ask(i, j);
        int x = (dist + 1) / 2;
        if (dist & 1)
            ans1[i] = x,
            ans2[i] = (n + 1) / 2 + (n & 1 ? - x : x);
        else
            ans1[i] = n - x,
            ans2[i] = (n + 1) / 2 + (n & 1 ? x : - x);
    }

    cout << "! ";
    for (int& x : ans1)
        cout << x << " ";
    for (int& x : ans2)
        cout << x << " ";
    cout << nl;
    int x; cin >> x;
    assert(x != -2);
}

signed main() {
    int T = 1;
    cin >> T;
    while (T--) solve();
}