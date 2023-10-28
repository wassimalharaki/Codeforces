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

    int n; cin >> n;

    int acmin = INF, premin = INF, acmax = 0, premax = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (a > acmax)
            premax = acmax, acmax = a;
        else if (a > premax)
            premax = a;
        
        if (a < acmin)
            premin = acmin, acmin = a;
        else if (a < premin)
            premin = a;
    }
    cout << min(acmax - premin, premax - acmin);

    return 0;
}