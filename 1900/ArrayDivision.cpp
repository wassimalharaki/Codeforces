#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;

    v<int> a(n);
    for (int& x : a) cin >> x;
    int sum = accumulate(a.begin(), a.end(), 0ll);

    if (sum & 1) {
        cout << "NO" << nl;
        return;
    }

    v<int> pref, suff;
    int j = 0, x = sum >> 1, l = 0;
    for (; j < n and l + a[j] < x; j++)
        pref.push_back(a[j]), l += a[j];

    for (; j < n; j++)
        suff.push_back(a[j]);
    
    v<int> left(pref.size() + 1), right(suff.size() + 1);
    partial_sum(pref.rbegin(), pref.rend(), left.begin() + 1);
    partial_sum(suff.begin(), suff.end(), right.begin() + 1);
    
    if (l == x)
        cout << "YES" << nl;
    else {
        for (int& y : pref)
            if (binary_search(right.begin(), right.end(), x - (l - y))) {
                cout << "YES" << nl;
                return;
            }

        for (int& y : suff)
            if (binary_search(left.begin(), left.end(), l + y - x)) {
                cout << "YES" << nl;
                return;
            }
        
        suff.erase(suff.begin());
        for (int& y : suff)
            if ((l += y) == x) {
                cout << "YES" << nl;
                return;
            }

        cout << "NO" << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}