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

        vi nums(n);
        int min = INF, imin;
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            if (nums[i] < min) {
                min = nums[i];
                imin = i;
            }
        }

        vi b, c;
        b.pb(min);
        for (int i = 0; i < n; i++) {
            if (i == imin)
                continue;
            nums[i] == min ?
                b.pb(nums[i]):
                c.pb(nums[i]);
        }

        if (b.size() && c.size()) {
            cout << b.size() << " " << c.size() nl;
            for (int i = 0; i < b.size(); i++)
                cout << b[i] << " ";
            cout nl;
            for (int i = 0; i < c.size(); i++)
                cout << c[i] << " ";
            cout nl;
        }
        else
            cout << -1 nl;
    }

    return 0;
}