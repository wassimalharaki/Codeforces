#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

int ask(int x) {
    cout << "- " << x << endl;
    int y; cin >> y;
    return y;
}

void ans(int x) {
    cout << "! " << x << endl;
}

void solve() {
    int n; cin >> n;
 
    int x = 0, i = 0, rem = 0;
    while (n > rem) {
        int y = ask(1 << i);
        x += 1 << i;
        if (y >= n)
            x += 1 << i, rem++;
        n = y, i++;
    }
    ans(x);
}

signed main() {
    int T = 1;
    cin >> T;
    while (T--) solve();
}