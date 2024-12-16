#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;

    v a(n, v<int>(n));
    int lim = 0;
    for (auto& x : a)
        for (int& y : x) {
            char c; cin >> c;
            y = c == 'X';
            lim += y;
        }
    lim /= 3;

    auto valid = [&](int i, int j) -> bool {
        return i >= 0 and j >= 0 and i < n and j < n;
    };
    
    auto horz = [&](int i, int j, v<v<int>>& b) -> bool {
        for (int k = 0; k < 3; k++)
            if (not valid(i, j + k) or b[i][j + k] != 1)
                return 0;
        return 1;
    };

    auto vert = [&](int i, int j, v<v<int>>& b) -> bool {
        for (int k = 0; k < 3; k++)
            if (not valid(i + k, j) or b[i + k][j] != 1)
                return 0;
        return 1;
    };

    auto ans = a;
    for (int _ = 0; _ < 3; _++) {
        int l = _, cnt = 0;
        auto b = a;
        for (int i = 0; i < n; i++, l = (l + 1) % 3)
            for (int j = l; j < n; j += 3)
                for (int k = -2; k <= 0; k++)
                    if (horz(i, j + k, b) or vert(i + k, j, b))
                        b[i][j] = -1, cnt++;
        if (cnt <= lim)
            ans = b;
    }

    for (auto& x : ans) {
        for (int& y : x)
            cout << (y == 1 ? 'X' : y == 0 ? '.' : 'O');
        cout << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}