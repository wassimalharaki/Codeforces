#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector
#define all(v) v.begin(), v.end()

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

vector<int> divisors(int n) {
    vector<int> divs;

    for (int i = 1; i * i <= n; i++)
        if (n % i == 0)
            divs.push_back(i);

    for (int i = divs.size() - 1; i >= 0; i--)
        if (n / divs[i] != divs[i])
            divs.push_back(n / divs[i]);

    return divs;
}

void solve() {
    int n, x; cin >> n >> x;
    v<int> divs1 = divisors(n - x);
    v<int> divs2 = divisors(n + x - 2);

    set<int> ok;
    for (int& a : divs1) {
        if (a & 1) continue;
        int k = (a + 2) / 2;
        if (k >= x and k < n)
            ok.insert(k);
    }

    for (int& a : divs2) {
        if (a & 1) continue;
        int k = (a + 2) / 2;
        if (k >= x and k < n)
            ok.insert(k);
    }
    
    cout << ok.size() << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}