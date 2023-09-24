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
        int k; cin >> k;

        int layer = (int) sqrt(k);
        if (layer != sqrt(k))
            layer++;
        
        int start = pow(layer - 1, 2) + 1;
        int end = pow(layer, 2);
        int middle = (start + end) / 2;

        int r, c;
        if (k < middle)
            c = layer, r = k - start + 1;
        else if (k > middle)
            r = layer, c = end - k + 1;
        else
            r = c = layer;
        cout << r << " " << c nl;
    }

    return 0;
}