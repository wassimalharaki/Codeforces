#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

int ask(int i, int j, int k) {
    i++, j++, k++;
    cout << "? " << i << " " << j << " " << k << endl;
    int x; cin >> x;
    assert(x != -1);
    return x;
}

void ans(int i, int j) {
    i++, j++;
    cout << "! " << i << " " << j << endl;
}

array<int, 2> find(array<int, 4> ind) {
    v<pair<int, v<int>>> a;
    for (int i = 0; i < 4; i++) {
        v<int> p;
        for (int j = 0; j < 4; j++)
            if (i != j)
                p.push_back(ind[j]);
        a.push_back({ask(p[0], p[1], p[2]), p});
    }
    sort(a.rbegin(), a.rend());
    array<int, 2> b; int j = 0;
    auto x = a[1].second;
    for (int& k : a[0].second)
        if (count(x.begin(), x.end(), k))
            b[j++] = k;
    return b;
}

void solve() {
    int n; cin >> n;

    int a = 0, b = 1;
    for (int i = 2; i + 1 < n; i += 2) {
        auto x = find({a, b, i, i + 1});
        a = x[0], b = x[1];
    }
    if (n & 1) {
        int k = 1;
        while (k == a or k == b) k++;
        auto x = find({a, b, k, n - 1});
        a = x[0], b = x[1];
    }
    ans(a, b);
}

signed main() {
    int T = 1;
    cin >> T;
    while (T--) solve();
}