#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define all(v) v.begin(), v.end()
#define nl << '\n'
#define v vector
#define vi vector<int>
#define pii pair<int, int>

int32_t main() {
    fast

    int t;

    cin >> t;

    while(t--) {
        string x;
        
        cin >> x;

        int initial = x[0] - '0';

        int digits = (initial - 1) * 10;
        digits += (1 + x.size()) * (x.size()) / 2;

        cout << digits nl;
    }

    return 0;
}