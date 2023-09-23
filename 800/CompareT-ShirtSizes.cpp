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
        string a, b; cin >> a >> b;
        int n = a.size(), m = b.size();

        if (a[n - 1] == b[m - 1])
            if (a[n - 1] == 'L')
                cout << ((n > m)? '>' : ((n == m)? '=' : '<')) nl;
            else
                cout << ((n > m)? '<' : ((n == m)? '=' : '>')) nl;
        else if (a[n - 1] == 'L')
            cout << '>' nl;
        else if (a[n - 1] == 'M' && b[m - 1] == 'S')
            cout << '>' nl;
        else
            cout << '<' nl;
    }

    return 0;
}