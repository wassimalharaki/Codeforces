#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

int front(v<int> a) {
    int n = a.size();
    v<int> in(n);
    for (int i = 0; i < n; i++)
        in[a[i]] = i;
    
    int ans = n;
    for (int i = 0; i < n; i++) {
        int l = 0, prev = -1;
        for (int j = i; j < n; j++)        
            if (in[j] > prev)
                prev = in[j], l++;
            else
                break;
        ans = min(ans, n - l);
    }
    return ans;
}

int back(v<int> a) {
    int n = a.size();
    v<int> in(n);
    for (int i = 0; i < n; i++)
        in[a[i]] = i;
    
    int ans = n;
    for (int i = n - 1; i >= 0; i--) {
        int r = 0, prev = n;
        for (int j = i; j >= 0; j--)
            if (in[j] < prev)
                prev = in[j], r++;
            else
                break;
        ans = min(ans, n - r);
    }
    return ans;
}

void solve() {
    int n; cin >> n;

    v<int> a(n);
    for (int& x : a) cin >> x;

    {
        v<int> b(a);
        sort(b.begin(), b.end());
        b.resize(unique(b.begin(), b.end()) - b.begin());
        for (int& x : a)
            x = lower_bound(b.begin(), b.end(), x) - b.begin();
    }
    cout << min(front(a), back(a)) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}