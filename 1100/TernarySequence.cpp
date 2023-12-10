#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define nl << '\n'
#define pii pair<int, int>
#define v vector
#define vi v<int>
#define vvi v<vi>
#define vpii v<pii>
#define mp make_pair
#define pb push_back
#define INF LONG_LONG_MAX
#define F first
#define S second

int32_t main() {
    fast;

    int T; cin >> T;
    
    while (T--) {
        int a0, a1, a2; cin >> a0 >> a1 >> a2;
        int b0, b1, b2; cin >> b0 >> b1 >> b2;

        int sum = 0;

        int sub = min(a2, b1);
        sum += sub * 2;
        a2 -= sub, b1 -= sub;
        sub = min(a2, b2);
        a2 -= sub, b2 -= sub;
        sub = min(a2, b0);
        a2 -= sub, b0 -= sub;

        sub = min(a1, b1);
        a1 -= sub, b1 -= sub;
        sub = min(a1, b0);
        a1 -= sub, b0 -= sub;

        sub = min(a0, b2);
        a0 -= sub, b2 -= sub;
        sub = min(a0, b1);
        a0 -= sub, b1 -= sub;
        sub = min(a0, b0);
        a0 -= sub, b0 -= sub;

        sum -= a1 * 2;
        cout << sum nl;
    }

    return 0;
}