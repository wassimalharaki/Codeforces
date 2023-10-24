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
        int n; cin >> n;

        if (n < 5 and n != 3) {
            cout << -1 nl;
            continue;
        }
        
        int mod = n % 3;
        if (mod == 0)
            cout << n / 3 << " 0 0" nl;
        else if (mod == 1)
            cout << n / 3 - 2 << " 0 1" nl;
        else if (mod == 2)
            cout << n / 3 - 1 << " 1 0" nl;
    }

    return 0;
}