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
        int twos = 0;
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            if (a == 2)
                twos++;
            nums[i] = twos;
        }

        twos & 1 ?
            cout << -1 nl:
            cout << lower_bound(all(nums), twos / 2) - nums.begin() + 1 nl;
    }

    return 0;
}