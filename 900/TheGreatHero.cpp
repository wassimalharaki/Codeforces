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
        int a, b, n; cin >> a >> b >> n;
        
        v<pii> monsters(n);
        for (int i = 0; i < n; i++)
            cin >> monsters[i].F;
        for (int i = 0; i < n; i++)
            cin >> monsters[i].S;
        sort(all(monsters));
 
        int count = 0;
        for (int i = 0; i < n; i++) {
            int m = (monsters[i].S + a - 1) / a;
            b -= m * monsters[i].F;
            if (b <= 0)
                b + monsters[i].F > 0 ? count++ : count += 2;
        }
        cout << (count > 1 ? "NO" : "YES") nl;
    }
    
    return 0;
}