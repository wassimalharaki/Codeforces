#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, k; cin >> n >> k;

    if (k == 1)
        return void(cout << (n == 1 ? "YES\n1\n" : "NO\n"));
    if ((k * (n + 1)) & 1)
        return void(cout << "NO" << nl);
    if (n == 1)
        return void(cout << "NO" << nl);

    set<v<int>> ans;
    int ok = 0;
    if (k & 1) {
        v<int> a(n);
        iota(a.begin(), a.end(), 1ll);
        ans.insert(a);
        rotate(a.begin(), a.begin() + n / 2, a.end());
        ans.insert(a);
        a.clear();
        for (int i = n; i >= 1; i -= 2)
            a.push_back(i);
        for (int i = n - 1; i >= 2; i -= 2)
            a.push_back(i);
        ans.insert(a);
        k -= 3;
        ok = 1;
    }

    v<int> a(n);
    iota(a.begin(), a.end(), 1ll);
    do {
        v<int> b(n);
        for (int i = 0; i < n; i++)
            b[i] = n - a[i] + 1;
        if (not ans.count(a) and not ans.count(b))
            ans.insert(a), ans.insert(b);
    } while (next_permutation(a.begin(), a.end()) and ans.size() < k + ok * 3);

    if (ans.size() != k + ok * 3)
        return void(cout << "NO" << nl);
    cout << "YES" << nl;
    for (auto& x : ans) {
        for (auto y : x)
            cout << y << " ";
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