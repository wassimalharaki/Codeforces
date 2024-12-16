#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

int ask(v<int>& a) {
    cout << "? " << a.size();
    for (int& x : a)
        cout << " " << x + 1;
    cout << endl;
    int x; cin >> x;
    if (x == -1) exit(0);
    return x;
}

void answer(v<int>& ans) {
    cout << "!";
    for (int& x : ans)
        cout << " " << x;
    cout << endl;
    string s; cin >> s;
    if (s == "Incorrect")
        exit(0);
}

void solve() {
    int n, k; cin >> n >> k;

    v<v<int>> a(k);
    for (int i = 0; i < k; i++) {
        int m; cin >> m;
        a[i].resize(m);
        for (int& x : a[i])
            cin >> x, x--;
        sort(a[i].begin(), a[i].end());
    }

    v<int> have(n);
    iota(have.begin(), have.end(), 0ll);
    int max = ask(have);
    while (have.size() != 1) {
        v<int> left(have.begin(), have.begin() + have.size() / 2);
        int l = ask(left);
        if (l == max)
            have = left;
        else
            have = v<int>(have.begin() + have.size() / 2, have.end());
    }
    int j = have[0];

    v<int> ans(k);
    for (int i = 0; i < k; i++)
        if (binary_search(a[i].begin(), a[i].end(), j)) {
            v<int> b;
            for (int l = 0; l < n; l++)
                if (not binary_search(a[i].begin(), a[i].end(), l))
                    b.push_back(l);
            ans[i] = ask(b);
        }
        else ans[i] = max;
    answer(ans);
}

signed main() {
    int T = 1;
    cin >> T;
    while (T--) solve();
}