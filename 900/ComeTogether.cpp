#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define all(v) v.begin(), v.end()
#define nl << '\n'
#define v vector
#define vi vector<int>
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define INF LONG_LONG_MAX
#define F first
#define S second

int32_t main() {
    fast;

    int T; cin >> T;
    
    while (T--) {
        int xa, ya, xb, yb, xc, yc;
        cin >> xa >> ya >> xb >> yb >> xc >> yc;

        int common = 1;
        int bxdiff = xb - xa;
        int bydiff = yb - ya;
        int cxdiff = xc - xa;
        int cydiff = yc - ya;
        if (bxdiff < 0 and cxdiff < 0)
            bxdiff *= -1, cxdiff *= -1;
        if (bydiff < 0 and cydiff < 0)
            bydiff *= -1, cydiff *= -1;
        common += max(min(bxdiff, cxdiff), (int) 0);
        common += max(min(bydiff, cydiff), (int) 0);
        cout << common nl;
    }

    return 0;
}