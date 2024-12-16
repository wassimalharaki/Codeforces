#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

int ask(int l, int r) {
    cout << "xor " << l << " " << r << endl;
    cin >> l; assert(l != -1);
    return l;
}

void ans(int a, int b, int c) {
    cout << "ans " << a << " " << b << " " << c << endl;
}

void solve() {
    int n; cin >> n;

    if (ask(1, n)) {
        int a = -1, b = -1, c = -1;
        {
            int lo = 1, hi = n;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                int x = ask(1, mid);
                if (x)
                    a = x, hi = mid - 1;
                else
                    lo = mid + 1;
            }
        }
        {
            int lo = 1, hi = n;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                int x = ask(mid, n);
                if (x)
                    b = x, lo = mid + 1;
                else
                    hi = mid - 1;
            }
        }
        c = ask(1, n) ^ a ^ b;
        ans(a, b, c);
    }
    else {
        int a = -1, b = -1, c = -1;
        for (int i = 0; i <= __lg(n); i++) {
            int x = ask(1ll << i, 1ll << (i + 1));
            if (x) {
                a = x;
                break;
            }
        }
        {
            int lo = 1, hi = n;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                int x = ask(1, mid) ^ (mid >= a ? a : 0);
                if (x)
                    b = x, hi = mid - 1;
                else
                    lo = mid + 1;
            }
        }
        c = a ^ b;
        ans(a, b, c);
    }
}

signed main() {
    int T = 1;
    cin >> T;
    while (T--) solve();
}