#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

const int N = 30;

void solve() {
    int n; cin >> n;

    auto go = [&](int i, v<int>& a, auto&& self) -> int {
        int curr = 0, up = 0;
        for(; i >= 0 and a.size(); i--) {
            v<int> b;
            for (int& x : a)
                if (x & (1 << i))
                    b.push_back(x ^ (1 << i));
            curr = max(curr, self(i - 1, b, self) + up + (a[0] < (1 << i)));

            bool rem = 0;
            while (a.size() and a.back() >= (1 << i))
                a.pop_back(), rem = 1;
            curr = max(curr, up += rem);
        }
        if (a.size()) curr = max(curr, 1);
        return curr;
    };

    v<int> a(n);
    for (int& x : a) cin >> x;
    sort(a.begin(), a.end());
    cout << n - go(N - 1, a, go) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}