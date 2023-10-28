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
        int n; cin >> n;

        if (n & 1)
            for (int i = 0; i < n; i++)
                cout << "1 ";
        else if (n / 2 & 1)
            for (int i = 0; i < n / 2; i++)
                cout << "1 3 ";
        else if (n / 4 & 1)
            for (int i = 0; i < n / 4; i++)
                cout << "1 2 2 3 ";
        else {
            for (int i = 0; i < n - 2; i++)
                cout << "1 ";
            cout << n / 2 << " " << n / 2 + 2;
        }
        cout nl;
    }

    return 0;
}