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

bool check(int x) {
    if (x <= 0)
        return false;
    int lo = 0, hi = 1e4;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int val = mid * mid * mid;
        if (val == x)
            return true;
        else if (val > x)
            hi = mid - 1;
        else
            lo = mid + 1;
    }
    return false;
}

int32_t main() {
    fast;

    int T; cin >> T;
    
    while (T--) {
        int x; cin >> x;

        string answ = "NO";
        for (int i = 1; i <= 1e4; i++) {
            int b = x - i * i * i;
            if (check(b)) {
                answ = "YES";
                break;
            }
        }
        cout << answ nl;
    }

    return 0;
}