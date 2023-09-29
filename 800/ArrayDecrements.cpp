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

    int t; cin >> t;
    
    while (t--) {
        int n; cin >> n;

        vi a(n), b(n);
        int nonzero = -1;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            if (b[i] && nonzero == -1)
                nonzero = i;
        }

        if (nonzero == -1) {
            cout << "YES" nl;
            continue;
        }
        
        int diff = a[nonzero] - b[nonzero];
        if (diff < 0) {
            cout << "NO" nl;
            continue;
        }
        string answ = "YES";
        for (int i = 0; i < n; i++)
            if (a[i] - b[i] > diff || (a[i] - b[i] < diff && b[i])) {
                answ = "NO";
                break;
            }
        cout << answ nl;
    }

    return 0;
}