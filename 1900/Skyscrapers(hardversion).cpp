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
    int n; cin >> n;

    v<int> a(n);
    for (int& a : a) cin >> a;

    v<int> left(n), right(n);
    stack<int> ok;
    for (int i = 0; i < n; i++) {
        while (ok.size() and a[ok.top()] > a[i])
            ok.pop();
        
        if (ok.empty())
            left[i] += (i + 1) * a[i];
        else
            left[i] += a[i] * (i - ok.top()) + left[ok.top()];
        ok.push(i);
    }
    ok = stack<int>();
    for (int i = n - 1; i >= 0; i--) {
        while (ok.size() and a[ok.top()] > a[i])
            ok.pop();
        
        if (ok.empty())
            right[i] += (n - i) * a[i];
        else
            right[i] += a[i] * (ok.top() - i) + right[ok.top()];
        ok.push(i);
    }

    int mid = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        int curr = left[i] + right[i] - a[i];;
        if (curr > sum) {
            sum = curr;
            mid = i;
        }
    }
    
    v<int> ans(a);
    for (int i = mid - 1; i >= 0; i--)
        ans[i] = min(ans[i], ans[i + 1]);
    for (int i = mid + 1; i < n; i++)
        ans[i] = min(ans[i], ans[i - 1]);
    for (int& x : ans)
        cout << x << " ";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}