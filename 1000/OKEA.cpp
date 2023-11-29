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
        int n, k; cin >> n >> k;

        int odds = (n * k + 1) / 2;
        if (odds % k != 0) {
            cout << "NO" nl;
            continue;
        }

        cout << "YES" nl;
        for (int i = 0; i < odds; i++) {
            cout << 2 * i + 1 << " ";
            if ((i + 1) % k == 0)
                cout nl;
        }
        for (int i = 0; i < n * k - odds; i++) {
            cout << 2 * (i + 1) << " ";
            if ((i + 1) % k == 0)
                cout nl;
        }
    }

    return 0;
}