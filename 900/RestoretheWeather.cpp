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
        int n, k; cin >> n >> k;

        v<pii> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].F;
            a[i].S = i;
        }
        sort(all(a));
        
        vi b(n);
        for (int i = 0; i < n; i++)
            cin >> b[i];
        sort(all(b));

        for (int i = 0; i < n; i++)
            a[a[i].S].F = b[i];
        
        for (int i = 0; i < n; i++)
            cout << a[i].F << " ";
        cout nl;
    }

    return 0;
}