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
        int n; cin >> n;

        vi a(n), b(n - 1);
        for (int i = 0; i < n - 1; i++)
            cin >> b[i];
        
        a[0] = b[0], a[n - 1] = b[n - 2];
        for (int i = 1; i < n - 1; i++) {
            if (b[i] > b[i - 1])
                a[i] = b[i - 1];
            else
                a[i] = b[i];
        }
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout nl;
    }

    return 0;
}