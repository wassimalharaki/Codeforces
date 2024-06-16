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

v<v<int>> a(3, v<int>(3));

bool win_row(int p) {
    for (auto& x : a) {
        int cnt = 0;
        for (int& y : x)
            cnt += y == p;
        if (cnt == 3) return 1;
    }
    return 0;
}

bool win_col(int p) {
    for (int j = 0; j < 3; j++) {
        int cnt = 0;
        for (int i = 0; i < 3; i++)
            cnt += a[i][j] == p;
        if (cnt == 3) return 1;
    }
    return 0;
}

bool win_diag(int p) {
    int cnt = 0;
    for (int i = 0; i < 3; i++)
        cnt += a[i][i] == p;
    if (cnt == 3) return 1;
    cnt = 0;
    for (int i = 0; i < 3; i++)
        cnt += a[i][2 - i] == p;
    return cnt == 3;
}

bool draw() {
    for (auto& x : a)
        for (int& y : x)
            if (!y) return 0;
    return 1;
}

int get() {
    int n = 0;
    for (auto& x : a)
        for (int& y : x)
            n = n * 10 + y;
    return n;
}

map<char, int> id{
    {'.', 0},
    {'X', 1},
    {'0', 2}
};

void solve() {
    int n = 0;
    for (int i = 0; i < 9; i++) {
        char c; cin >> c;
        n = 10 * n + id[c];
    }
    
    set<int> first_win, second_win, draw_ok, second_turn, first_turn;
    auto go = [&](bool alt, auto&& go) -> void {
        if (win_row(1) or win_col(1) or win_diag(1)) {
            first_win.insert(get());
            return;
        }
        if (win_row(2) or win_col(2) or win_diag(2)) {
            second_win.insert(get());
            return;
        }
        if (draw()) {
            draw_ok.insert(get());
            return;
        }
        if (alt)
            second_turn.insert(get());
        else
            first_turn.insert(get());

        for (auto& x : a)
            for (int& y : x)
                if (!y) {
                    y = alt + 1;
                    go(!alt, go);
                    y = 0;
                }        
    };
    go(0, go);

    if (first_win.count(n))
        cout << "the first player won";
    else if (second_win.count(n))
        cout << "the second player won";
    else if (draw_ok.count(n))
        cout << "draw";
    else if (first_turn.count(n))
        cout << "first";
    else if (second_turn.count(n))
        cout << "second";
    else
        cout << "illegal";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}