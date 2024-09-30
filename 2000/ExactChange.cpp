#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;

    v<int> a(n);
    array<int, 3> rem; rem.fill(0);
    for (int& x : a) 
        cin >> x, rem[x % 3]++;
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    n = a.size();

    if (n == 1)
        cout << (a.back() + 2) / 3 << nl;
    else if (a.back() % 3 == 1)
        cout << a.back() / 3 + 1 + (rem[2] and (a.end()[-1] - 1 == a.end()[-2] or a.front() == 1)) << nl;
    else if (a.back() % 3 == 2)
        cout << a.back() / 3 + 1 + (rem[1] > 0) << nl;
    else
        cout << a.back() / 3 + (rem[1] or rem[2]) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}