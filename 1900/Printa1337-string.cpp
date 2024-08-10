#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

int get(int n) {
    int lo = 2, hi = 1e5, x = 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        if (mid * (mid - 1) / 2 <= n)
            lo = mid + 1, x = mid;
        else
            hi = mid - 1;
    }
    return x;
}

void solve() {
    int n; cin >> n;

    v<int> a;
    while (n) {
        int x = get(n);
        a.push_back(x);
        n -= x * (x - 1) / 2;
    }

    v<int> ans{1};
    for (int i = 1; a.size(); i++) {
        ans.push_back(3);
        while (a.size() and a.back() == i) {
            ans.push_back(7);
            a.pop_back();
        }
    }

    for (int& x : ans)
        cout << x;
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}