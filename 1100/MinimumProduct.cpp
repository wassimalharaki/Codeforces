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
        int a, b, x, y, n;
        cin >> a >> b >> x >> y >> n;
        if (b > a)
            swap(a, b), swap(x, y);
        int leasta = a - min(a - x, n);
        int leastb = b - min(b - y, n);
        if (leasta < leastb) {
            int sub = min(a - x, n);
            a -= sub; n -= sub;
            sub = min(b - y, n);
            b -= sub; n -= sub;
        }
        else {
            int sub = min(b - y, n);
            b -= sub; n -= sub;
            sub = min(a - x, n);
            a -= sub; n -= sub;
        }
        cout << a * b nl;
    }

    return 0;
}