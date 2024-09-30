#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

int ask(int a, int b) {
    cout << "? " << a << " " << b << endl;
    int x; cin >> x;
    return x;
}

void ans(int a) {
    cout << "! " << a << endl;
}

const int N = 30;

void solve() {
    int x = 0;

    for (int i = 0; i < N; i++)
        if ((ask((1 << i) - x, (1 << (i + 1)) + (1 << i) - x) & (1 << i)) == 0)
            x += 1 << i;
    ans(x);
}

signed main() {
    int T = 1;
    cin >> T;
    while (T--) solve();
}