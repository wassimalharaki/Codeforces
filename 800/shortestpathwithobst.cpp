#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define all(v) v.begin(), v.end()
#define nl << '\n'
#define v vector
#define vi vector<int>
#define pii pair<int, int>
#define mp make_pair
#define INF LONG_LONG_MAX
#define F first
#define S second

int32_t main() {
    fast

    int t; cin >> t;

    while (t--) {
        pii a, b, f; cin >> a.S >> a.F >> b.S >> b.F >> f.S >> f.F;

        if (a.F != b.F && a.S != b.S) {
            cout << abs(b.F - a.F) + abs(b.S - a.S) nl;
        }
        else if (a.F == b.F) {
            int answ = abs(b.F - a.F) + abs(b.S - a.S);
            if (f.F == a.F && f.S < max(a.S, b.S) && f.S > min(a.S, b.S))
                answ += 2;
            cout << answ nl;
        }
        else {
            int answ = abs(b.F - a.F) + abs(b.S - a.S);
            if (f.S == a.S && f.F < max(a.F, b.F) && f.F > min(a.F, b.F))
                answ += 2;
            cout << answ nl;
        }
    }

    return 0;
}