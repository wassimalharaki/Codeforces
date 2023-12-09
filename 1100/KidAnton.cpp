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

        vi a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        
        string answ = "YES";
        bool pos = 0, neg = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i]) {
                if (a[i] == 1)
                    pos = 1;
                else if (a[i] == -1)
                    neg = 1;
                continue;
            }
            
            if (b[i] > a[i] and not pos) {
                answ = "NO";
                break;
            }

            if (b[i] < a[i] and not neg) {
                answ = "NO";
                break;
            }

            if (a[i] == 1)
                pos = 1;
            else if (a[i] == -1)
                neg = 1;  
        }
        cout << answ nl;
    }

    return 0;
}