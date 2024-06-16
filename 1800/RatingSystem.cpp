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

int get(v<int>& a, int k) {
    int n = a.size(), ans = 0;
    bool ok = ans >= k;
    for (int i = 0; i < n; i++)
        if (ok)
            ans = max(k, ans + a[i]);
        else {
            ans = ans + a[i];
            ok |= ans >= k;
        }
    return ans;
}

void solve() {
    int n; cin >> n;

    v<int> a(n);
    for (int& x : a) cin >> x;
    v<int> pref(n + 1);
    partial_sum(a.begin(), a.end(), pref.begin() + 1);

    int curr = 0, ans = get(a, 0), k = 0;
    stack<int> neg;
    for (int i = n - 1; i >= 0; i--) {
        if (curr + pref[i + 1] > ans) {
            ans = curr + pref[i + 1];
            k = pref[i + 1];
        }
        if (a[i] > 0) {
            int me = a[i];
            while (neg.size() and me) {
                int sub = min(me, -neg.top());
                me -= sub;
                neg.top() += sub;
                if (neg.top() == 0) neg.pop();
            }
            curr += me;
        }
        else
            neg.push(a[i]);
    }
    cout << k << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}