#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector
#define all(v) v.begin(), v.end()

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

/*
get rid of matching pairs immediately

left with some amount of L and some amount of R
if L has 2 of the same color, what is smarter, flipping or
changing color?
L: red red
R: blue blue

i can do either
L: red red
R: blue yellow

its better to match L with R and not L with L 

L: red red green
R: blue yellow black
get rid of sames, use 2ops on diff

L: red red green
R: yellow

there will be either even in L and R or odd in L and R

*/

void solve() {
    int n, l, r; cin >> n >> l >> r;

    map<int, int> left, right;
    for (int i = 0; i < l; i++) {
        int a; cin >> a;
        left[a]++;
    }

    for (int i = 0; i < r; i++) {
        int a; cin >> a;
        right[a]++;
    }

    for (auto it = left.begin(); it != left.end();) {
        auto& [c, cnt] = *it;
        if (right.count(c)) {
            int sub = min(cnt, right[c]);
            cnt -= sub;
            right[c] -= sub;
            l -= sub; r -= sub;
            if (right[c] == 0) right.erase(c);
        }
        it++;
        if (cnt == 0) left.erase(c);
    }
    
    int ans = 0;
    if (r > l) {
        int diff = r - l;
        for (auto it = right.begin(); it != right.end();) {
            auto& [c, cnt] = *it;
            int sub = min(diff, cnt - (cnt & 1));
            diff -= sub;
            cnt -= sub;
            r -= sub;
            ans += sub / 2;
            it++;
            if (cnt == 0) right.erase(c);
        }

        diff = r - l;
        ans += diff;
        for (auto it = right.begin(); it != right.end();) {
            auto& [c, cnt] = *it;
            int sub = min(diff, cnt);
            diff -= sub;
            cnt -= sub;
            r -= sub;
            it++;
            if (cnt == 0) right.erase(c);
        }
    }
    else {
        int diff = l - r;
        for (auto it = left.begin(); it != left.end();) {
            auto& [c, cnt] = *it;
            int sub = min(diff, cnt - (cnt & 1));
            diff -= sub;
            cnt -= sub;
            l -= sub;
            ans += sub / 2;
            it++;
            if (cnt == 0) left.erase(c);
        }

        diff = l - r;
        ans += diff;
        for (auto it = left.begin(); it != left.end();) {
            auto& [c, cnt] = *it;
            int sub = min(diff, cnt);
            diff -= sub;
            cnt -= sub;
            l -= sub;
            it++;
            if (cnt == 0) left.erase(c);
        }
    }

    ans += l;
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}