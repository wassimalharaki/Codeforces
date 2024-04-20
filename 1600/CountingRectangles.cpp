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

const int N = 1e3 + 5;
int nums[N][N];
int prefix[N][N];

void build() {
    for (int i = 1; i < N; i++)
        for (int j = 1; j < N; j++)
            prefix[i][j] = nums[i][j] + prefix[i - 1][j] +
                prefix[i][j - 1] - prefix[i - 1][j - 1];
}

int get(int hl, int wl, int hr, int wr) {
    return prefix[hr][wr] - prefix[hl - 1][wr]
        - prefix[hr][wl - 1] + prefix[hl - 1][wl - 1];
}

void solve() {
    memset(nums, 0, sizeof(nums));
    int n, q; cin >> n >> q;

    for (int i = 0; i < n; i++) {
        int h, w; cin >> h >> w;
        nums[h][w] += h * w;
    }
    build();

    while (q--) {
        int hl, wl, hr, wr;
        cin >> hl >> wl >> hr >> wr;
        hl++; wl++; hr--; wr--;
        cout << get(hl, wl, hr, wr) << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    memset(prefix, 0, sizeof(prefix));
    int T = 1;
    cin >> T;
    while (T--) solve();
}