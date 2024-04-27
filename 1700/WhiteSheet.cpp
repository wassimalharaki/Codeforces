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

int inter_area(v<int>& s1, v<int>& s2) {
	return max(0ll, min(s1[2], s2[2]) - max(s1[0], s2[0])) *
	       max(0ll, min(s1[3], s2[3]) - max(s1[1], s2[1]));
}
 
int inter_area(v<int>& s1, v<int>& s2, v<int>& s3) {
    if (inter_area(s1, s2) == 0
            or inter_area(s2, s3) == 0
            or inter_area(s1, s3) == 0)
        return 0;
 
	v<int> s4{
        max(s1[0], s2[0]),
        max(s1[1], s2[1]),
        min(s1[2], s2[2]),
        min(s1[3], s2[3])
    };
    return inter_area(s3, s4);
}
 
int area(v<int>& r) {
    return (r[2] - r[0]) * (r[3] - r[1]);
}
 
void solve() {
    v<v<int>> r(3, v<int>(4));
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 4; j++)
            cin >> r[i][j];
    
    int vis_area = area(r[0]) - inter_area(r[0], r[1])
        - inter_area(r[0], r[2]) + inter_area(r[1], r[2], r[0]);
    cout << (vis_area > 0 ? "YES" : "NO");
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}