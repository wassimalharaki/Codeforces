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
        int n, k; cin >> n >> k;

        v<pii> ram(n);
        for (int i = 0; i < n; i++)
            cin >> ram[i].F;
        for (int i = 0; i < n; i++)
            cin >> ram[i].S;
        sort(all(ram));

        for (int i = 0; i < n; i++)
            if (ram[i].F <= k)
                k += ram[i].S;
            else 
                break;

        cout << k nl;
    }

    return 0;
}