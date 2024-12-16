#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

int ask(int l, int r) {
    if (l == r) return 0;
    cout << "? " << l << " " << r << endl;
    cin >> l; assert(l != -1); return l;
}

void ans(int i) {
    cout << "! " << i << endl;
}

void solve() {
    int n; cin >> n;

    v<int> a(n);
    iota(a.begin(), a.end(), 1);
    while (a.size() > 1) {
        v<int> b;
        n = a.size();
        for (int i = 0; i + 1 < n; i += 2) {
            int x = ask(a[i], a[i + 1]) - ask(a[i], a[i + 1] - 1);
            if (x)
                b.push_back(a[i]);
            else
                b.push_back(a[i + 1]);
        }
        if (n & 1)
            for (int i : {n - 2}) {
                int x = ask(a[i], a[i + 1]) - ask(a[i], a[i + 1] - 1);
                if (x and b.back() != a[i])
                    b.push_back(a[i]);
                else
                    b.push_back(a[i + 1]);
            }
        a.swap(b);
    }
    ans(a[0]);
}

signed main() {
    int T = 1;
    cin >> T;
    while (T--) solve();
}