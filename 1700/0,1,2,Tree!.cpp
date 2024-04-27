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

void solve() {
    int a, b, c; cin >> a >> b >> c;
 
    if (a + 1 != c) {
        cout << -1 << nl;
        return;
    }
 
    v<int> have;
    if (a) {
        have.push_back(2);
        a--;
    }
    else if (b) {
        have.push_back(1);
        b--;
    }
    else {
        c--;
    }
 
    int ans = 0;
    while (a or b or c) {
        ans++;
        if (have.empty()) {
            cout << -1 << nl;
            return;
        }
        v<int> next;
        for (int& i : have) {
            if (i == 2) {
                if (a) {
                    next.push_back(2);
                    a--;
                    if (a) {
                        next.push_back(2);
                        a--;
                    }
                    else if (b) {
                        next.push_back(1);
                        b--;
                    }
                    else if (c) {
                        c--;
                    }
                    else {
                        cout << -1 << nl;
                        return;
                    }
                }
                else if (b) {
                    next.push_back(1);
                    b--;
                    if (b) {
                        next.push_back(1);
                        b--;
                    }
                    else if (c) {
                        c--;
                    }
                    else {
                        cout << -1 << nl;
                        return;
                    }
                }
                else if (c) {
                    c--;
                    if (c) {
                        c--;
                    }
                    else {
                        cout << -1 << nl;
                        return;
                    }
                }
                else {
                    cout << -1 << nl;
                    return;
                }
            }
            else {
                if (a) {
                    next.push_back(2);
                    a--;
                }
                else if (b) {
                    next.push_back(1);
                    b--;
                }
                else if (c) {
                    c--;
                }
                else {
                    cout << -1 << nl;
                    return;
                }
            }
        }
        have = next;
    }
    if (have.size()) {
        cout << -1 << nl;
        return;
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}