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

char ask(int a, int b, int c, int d) {
    cout << "? " << a << " " << b << " " << c << " " << d << endl;
    char x; cin >> x;
    return x;
}

void solve() {
    int n; cin >> n;
    int big, a = 0, b = 0;
    for (int i = 0; i < n - 1; i++) {
        b++;
        char c = ask(a, a, b, b);
        if (c == '<') a = b;
    }
    big = a;
 
    a = 0, b = 1;
    if (a == big) a++;
    if (b == big or b == a) b++;
    set<int> store{a};
    for (int i = 0; i < n; i++) {
        if (b >= n) break;
        char c = ask(big, a, big, b);
        if (c == '=') store.insert(b);
        else if (c == '<') {
            a = b;
            store.clear();
            store.insert(a);
        }
        if (++b == big) b++;
    }
 
    v<int> nums;
    for (int x : store)
        nums.push_back(x);
 
    if (nums.size() == 1) {
        cout << "! " << big << " " << nums[0] << endl;
        return;
    }
 
    a = nums[0], b = nums[1];
    for (int i = 1; i < nums.size(); i++) {
        b = nums[i];
        char c = ask(a, a, b, b);
        if (c == '>') a = b;
    }
    cout << "! " << big << " " << a << endl;
}

signed main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}